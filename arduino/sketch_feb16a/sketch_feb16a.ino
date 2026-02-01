const int VOL_PIN = 8; 

void setup(){ 
 Serial.begin( 9600 ); 
} 

void loop(){ 
 int value; 
 float volt; 

 value = digitalRead( VOL_PIN ); 

 //volt = value * 5.0 / 1023.0; 

 Serial.print( "Value: " ); 
 Serial.println( value ); 
 //Serial.print( " Volt: " ); 
 //Serial.println( volt ); 


 delay( 500 ); 
} 