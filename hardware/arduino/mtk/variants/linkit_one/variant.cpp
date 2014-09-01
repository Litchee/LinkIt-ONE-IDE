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

#include "variant.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pins descriptions
 */
PinDescription g_APinDescription[]=
{
  { VM_DCL_HANDLE_INVALID, 10, PIO_END, 0 },      // 0   
  { VM_DCL_HANDLE_INVALID, 11, PIO_END, 0 },      // 1
  { VM_DCL_HANDLE_INVALID, 46, PIO_END, 1 },      // 2
  { VM_DCL_HANDLE_INVALID, 13, PIO_END, 1  },      // 3
#ifdef __LINKIT_V1__
  { VM_DCL_HANDLE_INVALID, 47, PIO_END, 1  },      // 4
  { VM_DCL_HANDLE_INVALID, 49, PIO_END, 1  },      // 5
  { VM_DCL_HANDLE_INVALID, 45, PIO_END, 1  },      // 6
#else
  { VM_DCL_HANDLE_INVALID, 40, PIO_END, 1  },      // 4
  { VM_DCL_HANDLE_INVALID, 3, PIO_END, 1  },      // 5
  { VM_DCL_HANDLE_INVALID, 25, PIO_END, 1  },      // 6
#endif
  { VM_DCL_HANDLE_INVALID, 50, PIO_END, 1  },      // 7
  { VM_DCL_HANDLE_INVALID, 48, PIO_END, 0  },      // 8
  { VM_DCL_HANDLE_INVALID, 19, PIO_END, 1  },      // 9
  { VM_DCL_HANDLE_INVALID, 26, PIO_END, 1  },      // 10
  { VM_DCL_HANDLE_INVALID, 28, PIO_END, 1  },      // 11
  { VM_DCL_HANDLE_INVALID, 29, PIO_END, 1  },      // 12
  { VM_DCL_HANDLE_INVALID, 27, PIO_END, 1  },      // 13
  { VM_DCL_HANDLE_INVALID, 0,  PIO_END, 0  },      // 14
  { VM_DCL_HANDLE_INVALID, 1,  PIO_END, 0  },      // 15
  { VM_DCL_HANDLE_INVALID, 2,  PIO_END, 0  },      // 16
#ifdef __LINKIT_V1__
  { VM_DCL_HANDLE_INVALID, 3,  PIO_END, 0  },      // 17
#else
  { VM_DCL_HANDLE_INVALID, -1,  PIO_END, 0  },      // 17
#endif
  { VM_DCL_HANDLE_INVALID, 44, PIO_END, 0  },      // 18
  { VM_DCL_HANDLE_INVALID, 43, PIO_END, 0  }      // 19
} ;

#ifdef __cplusplus
}
#endif

boolean changePinType(uint32_t ulPin, uint32_t ulPinType, VM_DCL_HANDLE* handle)
{
	VM_DCL_HANDLE gpio_handle; 

    if (ulPin > PIO_MAX_NUM)
    {
        return false;
    }

	

	if(g_APinDescription[ulPin].ulPinType == ulPinType && g_APinDescription[ulPin].ulHandle != VM_DCL_HANDLE_INVALID)
	{
		*handle = g_APinDescription[ulPin].ulHandle;
		return true;
	}

	*handle = VM_DCL_HANDLE_INVALID;

	if(ulPinType == PIO_DIGITAL)
	{
		if(g_APinDescription[ulPin].ulHandle != VM_DCL_HANDLE_INVALID)
		{
			vm_dcl_close(g_APinDescription[ulPin].ulHandle);
		}
		gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[ulPin].ulGpioId);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_0,NULL);
		vm_dcl_close(gpio_handle); 
	}
	else if(ulPinType == PIO_ANALOG)
	{
		if(g_APinDescription[ulPin].ulHandle != VM_DCL_HANDLE_INVALID)
		{
			vm_dcl_close(g_APinDescription[ulPin].ulHandle);
		}
		gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[ulPin].ulGpioId);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_2,NULL);
		vm_dcl_close(gpio_handle); 
	}
	else if(ulPinType == PIO_EINT)
	{
		if(g_APinDescription[ulPin].ulHandle != VM_DCL_HANDLE_INVALID)
		{
			vm_dcl_close(g_APinDescription[ulPin].ulHandle);
		}
		gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[ulPin].ulGpioId);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_2,NULL);
		vm_dcl_close(gpio_handle); 
	}
	else if(ulPinType == PIO_PWM)
	{
		if(g_APinDescription[ulPin].ulHandle != VM_DCL_HANDLE_INVALID)
		{
			vm_dcl_close(g_APinDescription[ulPin].ulHandle);
		}
		gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[ulPin].ulGpioId);

		if(ulPin == 3)
			vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_3,NULL);
		else
			vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_2,NULL);
		
		vm_dcl_close(gpio_handle); 
	}
	else if(ulPinType == PIO_SPI)
	{
		for(int i = 11; i<14; i++)
		{
			if(g_APinDescription[i].ulHandle != VM_DCL_HANDLE_INVALID)
			{
				vm_dcl_close(g_APinDescription[i].ulHandle);
			}
			gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[i].ulGpioId);
			vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_4,NULL);
			vm_dcl_close(gpio_handle); 
			g_APinDescription[i].ulHandle = VM_DCL_HANDLE_INVALID;

		}
	}
	else if(ulPinType == PIO_UART)
	{
		for(int i = 0; i<2; i++)
		{
			if(g_APinDescription[i].ulHandle != VM_DCL_HANDLE_INVALID)
			{
				vm_dcl_close(g_APinDescription[i].ulHandle);
			}
			gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[i].ulGpioId);
			vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_1,NULL);
			vm_dcl_close(gpio_handle); 
			g_APinDescription[i].ulHandle = VM_DCL_HANDLE_INVALID;

		}	
	}
	else if(ulPinType == PIO_I2C)
	{
		for(int i = 18; i<20; i++)
		{
			if(g_APinDescription[i].ulHandle != VM_DCL_HANDLE_INVALID)
			{
				vm_dcl_close(g_APinDescription[i].ulHandle);
			}
			gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[i].ulGpioId);
			vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_1,NULL);
			vm_dcl_close(gpio_handle); 
			g_APinDescription[i].ulHandle = VM_DCL_HANDLE_INVALID;

		}	
	}
	else
	{
		return false;
	}
	
	g_APinDescription[ulPin].ulPinType = (EPioType)ulPinType;

	return true;
}

void spiPinsRest(void)
{
	int i;
	VM_DCL_HANDLE gpio_handle; 
	
	for(int i = 11; i<14; i++)
	{
		gpio_handle = vm_dcl_open(VM_DCL_GPIO, g_APinDescription[i].ulGpioId);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_0,NULL);
		vm_dcl_close(gpio_handle); 
		g_APinDescription[i].ulHandle = VM_DCL_HANDLE_INVALID;
		g_APinDescription[i].ulPinType = PIO_DIGITAL;
	}
}

void setPinHandle(uint32_t ulPin, VM_DCL_HANDLE handle)
{
	g_APinDescription[ulPin].ulHandle = handle;
}

/*
 * UART objects
 */
RingBuffer rx_buffer1;
RingBuffer rx_buffer2;

UARTClass Serial(1, &rx_buffer1);
UARTClass Serial1(2, &rx_buffer2);

void serialEvent() __attribute__((weak));
void serialEvent1() __attribute__((weak));
void serialEventRun(void)
{
  if (Serial.available())
  {
  	 if(serialEvent)
  	 {
  	     serialEvent();
  	 }
  }
  if (Serial1.available())
  {
  	 if(serialEvent1)
  	 {
  	     serialEvent1();
  	 }
  }
}

#ifdef __cplusplus
extern "C" {
#endif

void init( void )
{
	int i;
	VM_DCL_HANDLE gpio_handle; 
	
	for(i=2;i<14;i++)
	{
		gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[i].ulGpioId);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_0,NULL);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_DIR_OUT, NULL);
            	vm_dcl_control(gpio_handle,VM_GPIO_CMD_WRITE_LOW, NULL);   
		vm_dcl_close(gpio_handle); 
	}
	for(i=18;i<20;i++)
	{
		gpio_handle = vm_dcl_open(VM_DCL_GPIO,g_APinDescription[i].ulGpioId);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_MODE_0,NULL);
		vm_dcl_control(gpio_handle,VM_GPIO_CMD_SET_DIR_OUT, NULL);
            	vm_dcl_control(gpio_handle,VM_GPIO_CMD_WRITE_LOW, NULL);   
		vm_dcl_close(gpio_handle); 
	}
#if 0
  SystemInit();

  // Set Systick to 1ms interval, common to all SAM3 variants
  if (SysTick_Config(SystemCoreClock / 1000))
  {
    // Capture error
    while (true);
  }

  // Disable watchdog
  WDT_Disable(WDT);

  // Disable pull-up on every pin
  for (int i = 0; i < PINS_COUNT; i++)
	  digitalWrite(i, LOW);

  // Enable parallel access on PIO output data registers
  PIOA->PIO_OWER = 0xFFFFFFFF;
  PIOB->PIO_OWER = 0xFFFFFFFF;
  PIOC->PIO_OWER = 0xFFFFFFFF;
  PIOD->PIO_OWER = 0xFFFFFFFF;

  // Initialize Serial port U(S)ART pins
  PIO_Configure(
    g_APinDescription[PINS_UART].pPort,
    g_APinDescription[PINS_UART].ulPinType,
    g_APinDescription[PINS_UART].ulPin,
    g_APinDescription[PINS_UART].ulPinConfiguration);
  digitalWrite(0, HIGH); // Enable pullup for RX0
  PIO_Configure(
    g_APinDescription[PINS_USART0].pPort,
    g_APinDescription[PINS_USART0].ulPinType,
    g_APinDescription[PINS_USART0].ulPin,
    g_APinDescription[PINS_USART0].ulPinConfiguration);
  PIO_Configure(
    g_APinDescription[PINS_USART1].pPort,
    g_APinDescription[PINS_USART1].ulPinType,
    g_APinDescription[PINS_USART1].ulPin,
    g_APinDescription[PINS_USART1].ulPinConfiguration);
  PIO_Configure(
    g_APinDescription[PINS_USART3].pPort,
    g_APinDescription[PINS_USART3].ulPinType,
    g_APinDescription[PINS_USART3].ulPin,
    g_APinDescription[PINS_USART3].ulPinConfiguration);

  // Initialize USB pins
  PIO_Configure(
    g_APinDescription[PINS_USB].pPort,
    g_APinDescription[PINS_USB].ulPinType,
    g_APinDescription[PINS_USB].ulPin,
    g_APinDescription[PINS_USB].ulPinConfiguration);

  // Initialize CAN pins
  PIO_Configure(
    g_APinDescription[PINS_CAN0].pPort,
    g_APinDescription[PINS_CAN0].ulPinType,
    g_APinDescription[PINS_CAN0].ulPin,
    g_APinDescription[PINS_CAN0].ulPinConfiguration);
  PIO_Configure(
    g_APinDescription[PINS_CAN1].pPort,
    g_APinDescription[PINS_CAN1].ulPinType,
    g_APinDescription[PINS_CAN1].ulPin,
    g_APinDescription[PINS_CAN1].ulPinConfiguration);

  // Initialize Analog Controller
  pmc_enable_periph_clk(ID_ADC);
  adc_init(ADC, SystemCoreClock, ADC_FREQ_MAX, ADC_STARTUP_FAST);
  adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
  adc_configure_trigger(ADC, ADC_TRIG_SW, 0); // Disable hardware trigger.
  adc_disable_interrupt(ADC, 0xFFFFFFFF); // Disable all ADC interrupts.
  adc_disable_all_channel(ADC);

  // Initialize analogOutput module
  analogOutputInit();
#endif
}

#ifdef __cplusplus
}
#endif

