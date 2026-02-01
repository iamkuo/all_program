#include "PMS.h"
SoftwareSerial Serial1(10, 11); // 將Arduino Pin2設定為RX, Pin3設定為TX
PMS pms(Serial1);
PMS::DATA data;

void setup()
{
  Serial.begin(9600);   
  pms.activeMode();  
}

void loop()
{
  if (pms.read(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }

  // Do other stuff...
}1