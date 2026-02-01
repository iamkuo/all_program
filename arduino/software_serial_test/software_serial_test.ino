#include <SoftwareSerial.h>

SoftwareSerial Serial1(10, 11); // Arduino Pin 10 as RX, Pin 11 as TX

void setup() {
  Serial.begin(9600);    // Communication with Serial Monitor
  Serial1.begin(115200);   // Communication with PMS5003
  Serial.println("Testing PMS5003 Raw Output");
}

void loop() {
  while (Serial1.available()) {       // Check if data is available from PMS5003
    char c = Serial1.read();          // Read one byte
    Serial.print(c);                  // Print raw data to Serial Monitor
  }
}
