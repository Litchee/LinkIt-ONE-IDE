#include <Servo.h> 
int i;
Servo myservo;

void setup() {
    //Serial.begin(115200);
    myservo.attach(9);
    myservo.write(90);

}

void loop() {
    delay(1000);
    vm_log_info("loop");

    i += 3;
    if (i == 180)
        i = 0;
    myservo.write(i);

}

