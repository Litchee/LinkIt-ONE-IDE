#include <LEEPROM.h>

#define ard_log Serial.printf

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  ard_log("setup");
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  ard_log("loop");
  delay(2000);
  
    byte a = 1;
  

  EEPROM.write(0, a);
  ard_log("written");
  delay(1000);
  byte b = EEPROM.read(0);
  ard_log("read [%d]", b);
  if (a == b)
  {
  	// do something.
  	delay(1000);
  }
  
  
  

}
