/*
 * Starter Kit for LinkIt One - Lesson 5
 * Color Pannels
 * This demo will show you how to change the color of a RGB LED 
 * via 3 buttons
 *
 * Auther: Loovee
 * 2014-6-18
 *
 * Connection:
 * 
 * RGB_LED_R connect to D7
 * RGB_LED_G connect to D8
 * RGB_LED_B connect to D9
 *
 * Button1 connect to D2
 * Button2 connect to D3
 * Button3 connect to D4
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

const int ledR = 7;
const int ledG = 8;
const int ledB = 9;

const int buttonR = 2;
const int buttonG = 3;
const int buttonB = 4;


void setup()
{
    pinMode(ledR, OUTPUT);                          // set all led pin OUTPUT
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
    
    pinMode(buttonR, INPUT);                        // set all button pin INPUT
    pinMode(buttonG, INPUT);
    pinMode(buttonB, INPUT);
}

void loop()
{
    int stateR = 1-digitalRead(buttonR);            // get state of button
    int stateG = 1-digitalRead(buttonG);
    int stateB = 1-digitalRead(buttonB);
    
    digitalWrite(ledR, stateR);                     // set led
    digitalWrite(ledG, stateG);
    digitalWrite(ledB, stateB);
    
    delay(10);
}