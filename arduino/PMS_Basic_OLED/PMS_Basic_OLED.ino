#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SD.h>

#define DHTPIN  2     // 連接digital 2號針腳
#define DHTTYPE DHT22 // DHT 22 (AM2302)

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
const int chipSelect = 10;
File myFile;

SoftwareSerial pms5003tSerial(12, 13);
int pmat10_ = 0;
int pmat25_ = 0;
int pmat100_ = 0;

void retrieveaqi() {
  int count = 0;
  unsigned char c;
  unsigned char high;
  while (pms5003tSerial.available()) {
    c = pms5003tSerial.read();
    if ((count == 0 && c != 0x42) || (count == 1 && c != 0x4d)) {
      break;
    }
    if (count > 27) {
      break;
    } else if (count == 10 || count == 12 || count == 14 || count == 24 || count == 26) {
      high = c;
    } else if (count == 11) {
      pmat10_ = 256 * high + c;
    } else if (count == 13) {
      pmat25_ =  256 * high + c;
    } else if (count == 15) {
      pmat100_ = 256 * high + c;
    }
    count++;
  }
  Serial.print("Yee");
  while (pms5003tSerial.available()) pms5003tSerial.read();
}

void setup() {

  pinMode(8, OUTPUT);
  digitalWrite(8,HIGH);
  
  Serial.begin(9600);
  pms5003tSerial.begin(9600);

  

  while (!Serial);

  Serial.println("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("1. is a card inserted?");
    Serial.println("2. is your wiring correct?");
    Serial.println("3. did you change the chipSelect pin to match your shield or module?");
    Serial.println("Note: press reset button on the board and reopen this Serial Monitor after fixing your issue!");
    while (true);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  //Serial.println("initialization111111111111");
/*
  myFile = SD.open("test.txt", FILE_WRITE);
  if (!myFile) {
    Serial.println("error opening test.txt");
  }

  if (myFile.size() == 0) {
    myFile.println("PM1.0,PM2.5,PM10,Temperature,Humidity"); // CSV 標題行
  }
  myFile.close();
  Serial.print("Yee");
*/
  while (pmat10_ == 0) {
    Serial.print("fuck u");
    retrieveaqi();
    delay(1000);
  }
  dht.begin(); // 初始化感應器
  Serial.println("DHT");
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  retrieveaqi();
  Serial.print("PM1.0: ");
  Serial.print(pmat10_);
  Serial.print(", PM2.5: ");
  Serial.print(pmat25_);
  Serial.print(", PM10: ");
  Serial.print(pmat100_);

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  } else {
    Serial.print(", Temperature: ");
    Serial.print(event.temperature);
    Serial.print(" *C");
  }

  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.print("Error reading humidity!");
  } else {
    Serial.print(", Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }

  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
    myFile.print(pmat10_);
    myFile.print(",");
    myFile.print(pmat25_);
    myFile.print(",");
    myFile.print(pmat100_);
    myFile.print(",");
    myFile.print(event.temperature);
    myFile.print(",");
    myFile.println(event.relative_humidity);
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
  delay(delayMS);
}