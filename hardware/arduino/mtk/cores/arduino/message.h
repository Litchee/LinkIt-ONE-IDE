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

#ifndef _MESSAGE_
#define _MESSAGE_
#include "arduino.h"
#include "vmsys.h"
#include "vmthread.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VM_MSG_ARDUINO_CALL  3000

typedef boolean (*remote_call_ptr)(void* user_data);

typedef struct _msg_struct
{
	VM_SIGNAL_ID signal;
	remote_call_ptr remote_func;
	void* userdata;
}msg_struct;

#ifdef __cplusplus
}
#endif

#endif /* _MESSAGE_ */
