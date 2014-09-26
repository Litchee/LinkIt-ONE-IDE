/*
 * Starter Kit for LinkIt One - Lesson 2
 * Control LED
 * This is the "hello world" of Arduino. We will control a LED here
 *
 * Auther: Loovee
 * 2014-6-18
 *
 * Connection:
 * -LED connect to 13
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

void setup()
{
    pinMode(pinLED, OUTPUT);                // set direction of D13-OUTPUT
}

void loop()
{
    digitalWrite(pinLED, HIGH);             // LED on
    delay(1000);
    digitalWrite(pinLED, LOW);              // LED off
    delay(100);
}