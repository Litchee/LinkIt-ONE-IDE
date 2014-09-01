/*
 * digital I/O for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@bug.st>.
 * All rights reserved.
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef _WIRING_DIGITAL_
#define _WIRING_DIGITAL_

#ifdef __cplusplus
 extern "C" {
#endif

  // DESCRIPTION
	//  Sets up modes for assigned pins.
  //  LinkIt One supports 3 pin modes:
  //  INPUT: Used for reading voltage (HIGH or LOW) or sensor. In INPUT mode when the circuit is at high impedance, similar to serially connecting a big resistance in the circuit, the pin can read accurate voltage value. However, this pin may not have enough voltage to activate peripheral devices, e.g. LED.
  //  INPUT_PULLUP: Similar to INPUT mode, used for reading voltage of sensor. However in this mode, the pin is often at high voltage when the sensor is disabled and turns to low voltage when the sensor is enabled, which is opposite to its behavior in INPUT mode.
  //  OUTPUT: Used for controlling peripheral devices. In OUTPUT mode when the circuit is at low impedance, the pin has enough voltage to activate or control other devices but cannot read the voltage of sensor.
	// RETURNS
	//  N/A
	// EXAMPLE
	//	<code>
	//  #define LED  13
	//	void setup()
	//  {
	//    pinMode(LED, OUTPUT);
	//  }
	//	void loop()
	//  {
	//    digitalWrite(LED, HIGH);
	//    delay(3000);
	//    digitalWrite(LED, LOW);
	//    delay(3000);
	//  }
	//	</code> 
extern void pinMode(
  uint32_t dwPin,   // [IN] Pin number that needs to be set with a mode
  uint32_t dwMode   // [IN] Mode of pin (INPUT, INPUT_PULLUP or OUTPUT)
  ) ;

  // DESCRIPTION
	//  Sets assigned pins to high voltage (3.3V) or low voltage (0V).
	// RETURNS
	//  N/A
	// EXAMPLE
	//	<code>
	//  #define LED  13
	//	void setup()
	//  {
	//    pinMode(LED, OUTPUT);
	//  }
	//	void loop()
	//  {
	//    digitalWrite(LED, HIGH);
	//    delay(3000);
	//    digitalWrite(LED, LOW);
	//    delay(3000);
	//  }
	//	</code> 
extern void digitalWrite(
  uint32_t dwPin,   // [IN] Pin number that needs to be set with a value
  uint32_t dwVal    // [IN] HIGH or LOW
   ) ;
 
  // DESCRIPTION
	//  Reads voltage of assigned pin, HIGH or LOW.
	// RETURNS
	// HIGH or LOW
	// EXAMPLE
	//	<code>
	//  #define LED     13
	//  #define BUTTON  16
	//	void setup()
	//  {
	//    pinMode(LED, OUTPUT);
	//    pinMode(BUTTON, INPUT);
	//  }
	//	void loop()
	//  {
	//    int result = 0;
	//    int n= digitalRead(BUTTON);
	//    if (n == HIGH)
	//    {
	//        digitalWrite(LED, LOW);
	//        delay(2000);
	//    }
	//    else
	//    {
	//        digitalWrite(LED, HIGH);
	//        delay(2000);
	//    }
	//  }
	//	</code> 
extern int digitalRead( 
  uint32_t ulPin   // [IN] Pin number that needs to read voltage
  ) ;

#ifdef __cplusplus
}
#endif

#endif /* _WIRING_DIGITAL_ */
