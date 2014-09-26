// Controlling a servo position using a potentiometer (variable resistor)
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

#include <Servo.h>

Servo myservo;              // create servo object to control a servo

int potpin = A0;            // analog pin used to connect the potentiometer
int val;                    // variable to read the value from the analog pin

int pos     = 1;
int offset  = 1;
int speed   = 0;


void setup()
{
    Serial.begin(9600);
    myservo.attach(3);      // attaches the servo on pin 9 to the servo object
}


void loop()
{

    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
    
    speed = map(val, 0, 1023, 100, 1);
    Serial.println(speed);
    
    myservo.write(pos);
    
    if(pos == 150 || pos == 0)
    {
        offset = 0-offset;
    }
    
    pos += offset;
    delay(speed);
    
}