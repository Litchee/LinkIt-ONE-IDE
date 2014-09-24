/*
 * Starter Kit for LinkIt One - Lesson 6
 * Color Gradient LED
 * This demo will show you how to change the color of a RGB LED 
 * via a potentiometer 
 *
 * Auther: Loovee
 * 2014-6-18
 *
 * Connection:
 * 
 * - LED_R connect to D3
 * - LED_G connect to D5
 * - LED_B connect to D6
 * - Potentiometer  connect to A0
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

const int pinR = 3;                             // pin define of RGB LED
const int pinG = 5;
const int pinB = 6;

const int pinPoten = A0;                        // Potentiometer connect to A0


void makeRGB(int dta)
{
    int R = 0;
    int G = 0; 
    int B = 0;

    if(dta < 256)
    {
        R = dta; 
        G = 0;
        B = 0;
    }
    else if(dta < 512)
    {
        R = 255 - (dta-256);
        G = dta - 256;
        B = 0;
    }
    else if(dta < 768)
    {
        R = 0;
        G = 255 - (dta - 512);
        B = dta-512;
    }
    else
    {
        R = dta - 768;
        G = 0;
        B = 255 - (dta - 768);
    }
    
    analogWrite(pinR, R);
    analogWrite(pinG, G);
    analogWrite(pinB, B);
}

void setup()
{

}


void loop()
{
    int value = analogRead(pinPoten);
    makeRGB(value);
    delay(10);
}