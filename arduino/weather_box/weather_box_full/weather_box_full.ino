#include <SoftwareSerial.h>
#include <DHT.h>
#include <SPI.h>
#include <SD.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define READ_INTERVAL 60000 // 讀取間隔 60 秒

SoftwareSerial pmsSerial(8, 9); // RX = Pin 8, TX = Pin 9
DHT dht(DHTPIN, DHTTYPE);

const int chipSelect = 10; // SD卡CS引腳
unsigned long lastReadTime = 0;
bool headerWritten = false;
String fileName;

// 函數：生成唯一的檔案名稱，從編號 1 開始
String getUniqueFileName() {
    int fileNumber = 1;
    String baseName = "datalog_";
    String extension = ".csv";
    String newFileName;

    do {
        newFileName = baseName + String(fileNumber) + extension;
        fileNumber++;
    } while (SD.exists(newFileName));

    return newFileName;
}

void setup() {
    Serial.begin(9600);
    pmsSerial.begin(9600);
    dht.begin();
    
    Serial.print("初始化SD卡...");
    if (!SD.begin(chipSelect)) {
        Serial.println("SD卡初始化失敗！");
        while (1);
    }
    Serial.println("SD卡初始化完成");
    
    // 創建新的 CSV 檔案，使用編號
    fileName = getUniqueFileName();
    File dataFile = SD.open(fileName, FILE_WRITE);
    if (dataFile) {
        dataFile.println("Time(ms),PM1.0(ug/m3),PM2.5(ug/m3),PM10(ug/m3),Humidity(%),Temperature(C)");
        dataFile.print("Start Time: ");
        dataFile.println(millis());
        dataFile.close();
        headerWritten = true;
        Serial.print("新的 CSV 檔案已創建：");
        Serial.println(fileName);
    } else {
        Serial.println("無法創建新的 CSV 檔案");
    }
    Serial.println("程式啟動...");
}

void loop() {
    static uint8_t buffer[32];
    static int bufferIndex = 0;
    int pm1_0 = 0, pm2_5 = 0, pm10 = 0;
    float humidity = 0.0, temperature = 0.0;

    unsigned long currentTime = millis();
    if (currentTime - lastReadTime >= READ_INTERVAL) {
        // 讀取 PMS5003 數據
        while (pmsSerial.available()) {
            uint8_t byte = pmsSerial.read();
            if (bufferIndex == 0 && byte == 0x42) {
                buffer[bufferIndex++] = byte;
            } else if (bufferIndex == 1 && byte == 0x4D) {
                buffer[bufferIndex++] = byte;
            } else if (bufferIndex > 1) {
                buffer[bufferIndex++] = byte;
                if (bufferIndex == 32) {
                    pm1_0 = (buffer[10] << 8) + buffer[11];
                    pm2_5 = (buffer[12] << 8) + buffer[13];
                    pm10 = (buffer[14] << 8) + buffer[15];
                    Serial.print("PM1.0: ");
                    Serial.print(pm1_0);
                    Serial.print(" ug/m3, PM2.5: ");
                    Serial.print(pm2_5);
                    Serial.print(" ug/m3, PM10: ");
                    Serial.println(pm10);
                    bufferIndex = 0;
                }
            } else {
                bufferIndex = 0;
                Serial.println("PMS5003 數據幀未對齊");
            }
        }

        // 讀取 DHT22 數據
        humidity = dht.readHumidity();
        temperature = dht.readTemperature();
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("無法從 DHT22 讀取數據！");
        } else {
            Serial.print("濕度: ");
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("溫度: ");
            Serial.print(temperature);
            Serial.println(" °C");
        }

        // 將數據寫入 CSV 檔案
        File dataFile = SD.open(fileName, FILE_WRITE);
        if (dataFile) {
            dataFile.print(currentTime);
            dataFile.print(",");
            dataFile.print(pm1_0);
            dataFile.print(",");
            dataFile.print(pm2_5);
            dataFile.print(",");
            dataFile.print(pm10);
            dataFile.print(",");
            dataFile.print(humidity);
            dataFile.print(",");
            dataFile.println(temperature);
            dataFile.close();
            Serial.println("數據已寫入SD卡");
        } else {
            Serial.println("無法打開檔案進行寫入");
        }

        lastReadTime = currentTime;
    }
}