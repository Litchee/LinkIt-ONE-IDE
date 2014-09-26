/*
 * Starter Kit for LinkIt One - Advanced Lesson 6 - Flashing_LED
 *
 * The value of Slide Potentiometer will change the frequency of of the blink led
 *
 * Auther: Loovee
 * 2014-9-25
 *
 * Connection:
 * Led connect to D3
 * Slide Potentiometer connect to A0
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

const int pinLed    = 9;                        // pin of led1
const int pinAnalog = A0;                 
int led_state = 0;


void setup()
{
    pinMode(pinLed, OUTPUT);                   // set all pin OUTPUT

}

void loop()
{
    digitalWrite(pinLed, led_state);
    led_state = 1-led_state;
    
    int delay_time = analogRead(pinAnalog);
    delay(delay_time);
}