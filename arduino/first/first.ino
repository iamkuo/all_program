int pinled = 13;
int onoff = 0;
void setup() {
  pinMode(pinled,OUTPUT);
  pinMode(A7,INPUT_PULLUP);
}

void loop() {
  Serial.println(analogRead(A7));
  if (analogRead(A7) == 0) {
    onoff = (onoff+1)%2;
    digitalWrite(pinled,onoff);
    while(analogRead(A7) == 0){
      onoff = onoff;
    }
  }
}
