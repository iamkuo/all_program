#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define READ_INTERVAL 3000 // 讀取間隔 3 秒

SoftwareSerial pmsSerial(6, 7); // RX = Pin 6, TX = Pin 7
DHT dht(DHTPIN, DHTTYPE);

unsigned long lastReadTime = 0;

void setup() {
    Serial.begin(9600);
    pmsSerial.begin(9600);
    dht.begin();
    
    Serial.println("程式啟動...");
    Serial.println("初始化 DHT22 感測器...");
    delay(2000); // 等待 DHT22 穩定
    Serial.println("初始化 PMS5003 感測器...");
}

void loop() {
    static uint8_t buffer[32];
    static int bufferIndex = 0;
    int pm1_0 = 0, pm2_5 = 0, pm10 = 0;
    float humidity = 0.0, temperature = 0.0;
    bool dhtReadSuccess = false;
    bool pmsReadSuccess = false;

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
                    pmsReadSuccess = true;
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
            Serial.println("無法從 DHT22 讀取數據！請檢查接線或感測器");
        } else {
            dhtReadSuccess = true;
        }

        // 輸出數據到 Serial Monitor
        Serial.print("Time: ");
        Serial.print(currentTime);
        Serial.print(" ms, ");
        
        if (pmsReadSuccess) {
            Serial.print("PM1.0: ");
            Serial.print(pm1_0);
            Serial.print(" ug/m3, PM2.5: ");
            Serial.print(pm2_5);
            Serial.print(" ug/m3, PM10: ");
            Serial.print(pm10);
            Serial.print(" ug/m3, ");
        } else {
            Serial.print("PM1.0: N/A, PM2.5: N/A, PM10: N/A, ");
        }

        if (dhtReadSuccess) {
            Serial.print("Humidity: ");
            Serial.print(humidity);
            Serial.print(" %, Temperature: ");
            Serial.print(temperature);
            Serial.println(" °C");
        } else {
            Serial.println("Humidity: N/A, Temperature: N/A");
        }

        lastReadTime = currentTime;
    }
}