/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _UART_CLASS_
#define _UART_CLASS_

#include "HardwareSerial.h"
#include "RingBuffer.h"
#include "vmdcl.h"
#include "vmdcl_gpio.h"
#include "vmdcl_sio.h"
// Includes Atmel CMSIS
#include <chip.h>

/*****************************************************************************
 * Class UARTClass
 ****************************************************************************/
// UARTClass is designed for LinkIt One board connecte with other hardware device through UART
// EXAMPLE:
// <code>
// #define SENSOR 0
// int val = 0;
// void setup(){
// Serial.begin(9600);
// }
// void loop(){
// val = analogRead(SENSOR);
// Serial.println(val);
// delay(100);
// }
// </code>
class UARTClass : public HardwareSerial
{
  protected:
    RingBuffer *_rx_buffer ;
  protected:
    int _usbNum ;
    VM_DCL_HANDLE uart_handle;

  public:
// Constructor / Destructor
    UARTClass( int usbNum, RingBuffer* pRx_buffer ) ;
    
// Method
  public:
  	
 //  sets the data rate in bits per sencond for serial data transmission
 //
 // RETURNS
 // none
 //
 // EXAMPLE
 // <code>
 //  void setup(){
 //    Serial.begin(115200);
 //  }
 //  void loop(){}
 // </code> 
void begin( const uint32_t dwBaudRate //[IN] in bits per sencond(baud rate)
          ) ;

 //  disables serial communication, allowing the RX and TX pins to be used for 
 //  general input and output
 //
 // RETURNS
 // none  
void end( void ) ;

 //  get the number of bytes(characters)avaiable for reading from the serial port.
 //
 // RETURNS
 // the bumbers of bytes available to read
 //
 // EXAMPLE
 // <code>
 //  int numberscomingBytes = 0;
 //  void setup(){
 //    Serial.begin(115200);
 //  }
 //  void loop(){
 //   if(Serial.available()>0){
 //   numberscomingBytes = Serial.read();
 //   Serial.print(numberscomingBytes);
 //   }
 //  }
 // </code> 
int available( void ) ;

 //  returns the next byte of incoming serial data without removing it from the 
 //  internal serial buffer
 //
 // RETURNS
 // the first byte of incoming serial data available, -1 if no data is available
int peek( void ) ;

 //  reads incoming serial data
 //
 // RETURNS
 // the first byte of incoimng serial data avaiable, -a if no data is available
 //
 // EXAMPLE
 //	<code>
 //  int incomingdata = 0;
 //  void setup() {
 //    Serial.begin(9600);  
 //  }
 //  void loop() {
 //    if (Serial.available() > 0) {
 //      incomingdata = Serial.read();
 //      Serial.print("received data: ");
 //      Serial.println(incomingdata, DEC);
 //    }
 //  }
 //	</code> 
int read( void ) ;

 //  waits for the transmission of outgoing serial data to complete
 //
 // RETURNS none
void flush( void ) ;

// write a char 
//
// RETURNS
// the number of write
size_t write( const uint8_t c //[IN] input char
            ) ;
    
    friend void UartIrqHandler(void* parameter, VM_DCL_EVENT event, VM_DCL_HANDLE device_handle);
    
    // pull in write(str) and write(buf, size) from Print
    using Print::write ; 
    	
    // UART always active
    operator bool(); 
};

#endif // _UART_CLASS_
