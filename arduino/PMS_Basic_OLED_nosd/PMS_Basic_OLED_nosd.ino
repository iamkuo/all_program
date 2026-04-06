#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN  2     // 連接digital 2號針腳
#define DHTTYPE DHT22 // DHT 22 (AM2302)

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

SoftwareSerial pms5003tSerial(12, 13);
char pmat10_[50] = "";
char pmat25_[50] = "";
char pmat100_[50] = "";

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
      sprintf(pmat10_, "%d", 256 * high + c);
    } else if (count == 13) {
      sprintf(pmat25_, "%d", 256 * high + c);
    } else if (count == 15) {
      sprintf(pmat100_, "%d", 256 * high + c);
    }
    count++;
  }
  //Serial.print("Yee");
  while (pms5003tSerial.available()) pms5003tSerial.read();
}

void setup() {

  pinMode(8, OUTPUT);
  digitalWrite(8,HIGH);
  
  Serial.begin(9600);
  pms5003tSerial.begin(9600);

  dht.begin(); // 初始化感應器
  Serial.println("DHTxx Unified Sensor Example");
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;

  while (!Serial);

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("1. is a card inserted?");
    Serial.println("2. is your wiring correct?");
    Serial.println("3. did you change the chipSelect pin to match your shield or module?");
    Serial.println("Note: press reset button on the board and reopen this Serial Monitor after fixing your issue!");
    while (true);
  }

  Serial.println("initialization done.");
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
/*
  while (strlen(pmat10_) == 0) {
    Serial.print("fuck u");
    retrieveaqi();
    delay(1000);
  }
*/
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