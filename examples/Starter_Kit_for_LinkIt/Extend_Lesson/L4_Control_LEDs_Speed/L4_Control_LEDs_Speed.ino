/*
 * Starter Kit for LinkIt One - Advanced Lesson 4 - Leds speed
 *
 * This demo we will control 3 LEDs
 *
 * Auther: Loovee
 * 2014-9-25
 *
 * Connection:
 * Led1 connect to D2
 * Led2 connect to D3
 * Led3 connect to D4
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-
 * 1301  USA
 */

 
int speed = 5;                                  // speed is 0-10, the larger, the fast


const int pinLed1    = 2;                       // pin of led1
const int pinLed2    = 3;                       // pin of led2
const int pinLed3    = 4;                       // pin of led3
const int pinLed4    = 5;                       // pin of led4

int delay_time = 0;

void setup()
{
    pinMode(pinLed1, OUTPUT);                   // set all pin OUTPUT
    pinMode(pinLed2, OUTPUT);
    pinMode(pinLed3, OUTPUT);
    pinMode(pinLed4, OUTPUT);
    
    delay_time = 100*map(speed, 0, 10, 1100, 100);
}


void loop()
{
    digitalWrite(pinLed4, LOW);                 // led4 off
    digitalWrite(pinLed1, HIGH);                // led1 on
    
    delay(delay_time);
    
    digitalWrite(pinLed1, LOW);                 // led1 off
    digitalWrite(pinLed2, HIGH);                // led2 on
    
    delay(delay_time);
    
    digitalWrite(pinLed2, LOW);                 // led2 off
    digitalWrite(pinLed3, HIGH);                // led3 on
    
    delay(delay_time);
    
    digitalWrite(pinLed3, LOW);                 // led3 off
    digitalWrite(pinLed4, HIGH);                // led4 on
    
    delay(delay_time);
}