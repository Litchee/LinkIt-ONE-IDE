/*
 * Starter Kit for LinkIt One - Lesson 3
 * Control LED via a Button
 *
 * Auther: Loovee
 * 2014-6-18
 *
 * Connection:
 * -LED connect to D13
 * -Button connect to D2
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
 
const int pinLED = 13;                      // LED connect to D13
const int pinBtn = 2;                       // Button connect to D2


void setup()
{
    pinMode(pinLED, OUTPUT);                // set direction of D13-OUTPUT
    pinMode(pinBtn, INPUT);                 // set direction of D2-INPUT
}

void loop()
{
    if(digitalRead(pinBtn))                 // if button pressed
    {
        digitalWrite(pinLED, HIGH);         // led on
    }   
    else                                    // or
    {
        digitalWrite(pinLED, LOW);          // led of
    }
    
    delay(10);
}