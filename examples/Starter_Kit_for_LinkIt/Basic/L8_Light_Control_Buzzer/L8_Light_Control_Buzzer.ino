/*
 * Starter Kit for LinkIt One - Lesson 6
 * Light control LED
 * When light sensor was covered, led off else on.
 *
 * Auther: Loovee
 * 2014-6-18
 *
 * Connection:
 * 
 * - LED connect to D13
 * - Light Sensor connect to A0
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


#define LIGHT_COMP       150

 
const int pinLED   = 13;                        // pin define of LED
const int pinLight = A0;                        // pin define of Light Sensor


void setup()
{
    pinMode(pinLED, OUTPUT);
    pinMode(pinLight, INPUT);
}

void loop()
{
    int value = analogRead(pinLight);
    
    if(value > LIGHT_COMP)
    {
        digitalWrite(pinLED, HIGH);
    }
    else
    {
        digitalWrite(pinLED, LOW);
    }
    
    delay(10);
}