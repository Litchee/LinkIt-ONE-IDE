/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
#include "arduino.h"
#include "vmlog.h"
#include "BTClient.h"
#include "LBTClient.h"
#include "vmthread.h"
#include "LBT.h"
extern int addrStr2Mac(const char *MACAddr, LBTAddress &address);
extern void app_log_file(char *fmt, ...);
#ifdef LBT_DEBUG
#define APP_LOG(...) app_log_file(__VA_ARGS__); \ 
    vm_log_info(__VA_ARGS__)
#else
#define APP_LOG(...)
#endif

vm_thread_mutex_struct client_mutex = {0};
LBTClientClass::LBTClientClass(LBTRingBuffer* pRx_buffer) : m_post_write(0), m_post_read(0)
{
  _rx_buffer = pRx_buffer;
}

boolean LBTClientClass::begin(const uint8_t* pinCode)
{
    _LTaskClass::begin();
    
	m_signal_write = vm_signal_init();
	m_signal_read = vm_signal_init();
	
    LBTClientBeginContext c;
    c.ptr = this;
    c.result = false;
    c.is_set_pin = false;
	//boolean result = true;
    //APP_LOG("begin");
    if(pinCode!= NULL)
    {
    	int len = strlen((char*)pinCode);
    	if(len > LBT_PIN_CODE_BUFFER_SIZE - 1)
    	{
    		len = LBT_PIN_CODE_BUFFER_SIZE - 1;
    	}
    	c.is_set_pin = true;
    	memcpy(_pincode_buffer, pinCode, len+1);
    }  
    
    
	remoteCall(btClientBegin, &c);

    //APP_LOG("begin = %d", result);

	return c.result;
}

void LBTClientClass::end(void)
{
    _LTaskClass::stop();
	vm_signal_clean(m_signal_write);
	vm_signal_deinit(m_signal_write);
	vm_signal_clean(m_signal_read);
	vm_signal_deinit(m_signal_read);
	remoteCall(btClientEnd, (void*)NULL);
}

boolean LBTClientClass::connect(const char *MACAddr)
{
    LBTClientConnectContext c;
    
    LBTAddress addr = {0};
    c.address = &addr;
    if (0 > addrStr2Mac(MACAddr, *(c.address)))
        return false;
    
    remoteCall(btClientConnect, (void*)&c);

    return c.result;
}


boolean LBTClientClass::connect(LBTAddress &address)
{
    LBTClientConnectContext c;
    c.address = &address;
    remoteCall(btClientConnect, (void*)&c);

    return c.result;
}

boolean LBTClientClass::connected(void)
{
	boolean result = true;
    remoteCall(btClientConnected, &result);

    return result;
}

int LBTClientClass::scan(size_t time_out)
{
    LBTClientScanContext c;
    c.time_out= time_out;
    remoteCall(btClientScan, (void*)&c);

    return c.number;
}

boolean LBTClientClass::getDeviceInfo(size_t index, LBTDeviceInfo* device_info)
{
    LBTClientGetDeviceInfoContext c;
    c.index = index;
    c.device_info = device_info;
    remoteCall(btClientGetDeviceInfo, (void*)&c);

    return c.result;
}

size_t LBTClientClass::write(const uint8_t *buf, size_t size)
{
    LBTClientReadWriteContext c;
	c.buf = (void*)buf;
	c.len = size;
	
	if (!m_post_write)
	{
        APP_LOG((char*)"LBTClientClass::write wait");
        vm_signal_wait(m_signal_write); // wait for VM_SRV_SPP_EVENT_READY_TO_WRITE
        APP_LOG((char*)"LBTClientClass::write wait ok");
    }
    m_post_write = 0;
    vm_signal_clean(m_signal_write);

    remoteCall(btClientWrite, (void*)&c);
    m_post_write = 1;

	return c.lenProcessed;
}

void LBTClientClass::post_signal_write()
{
    APP_LOG((char*)"LBTClientClass::post_signal_write");
	vm_signal_post(m_signal_write);
	m_post_write = 1;
}

void LBTClientClass::post_signal_read()
{
    APP_LOG((char*)"LBTClientClass::post_signal_read");
	vm_signal_post(m_signal_read);
	m_post_read = 1;
}

int LBTClientClass::available(void)
{
  return (uint32_t)(LBT_SERIAL_BUFFER_SIZE + _rx_buffer->_iHead - _rx_buffer->_iTail) % LBT_SERIAL_BUFFER_SIZE;
}

int LBTClientClass::peek(void)
{
  if(_rx_buffer->_iHead == _rx_buffer->_iTail)
  	return -1;
  return _rx_buffer->_aucBuffer[_rx_buffer->_iTail];
}

int LBTClientClass::read(void)
{

  if(_rx_buffer->_iHead == _rx_buffer->_iTail)
  	return -1;
	if(client_mutex.guard == 0)
	{
		vm_mutex_create(&client_mutex);
	}
  vm_mutex_lock(&client_mutex);
  uint8_t uc = _rx_buffer->_aucBuffer[_rx_buffer->_iTail];
  _rx_buffer->_iTail = (unsigned int)(_rx_buffer->_iTail + 1) % LBT_SERIAL_BUFFER_SIZE;
  vm_mutex_unlock(&client_mutex);
  return uc;
}

void LBTClientClass::flush(void)
{
  while(read()!=-1);
}

size_t LBTClientClass::write(const uint8_t data)
{
  LBTClientReadWriteContext c;
	c.buf = (void*)&data;
	c.len = 1;
	
	if (!m_post_write)
	{
        APP_LOG((char*)"LBTClientClass::write wait");
        vm_signal_wait(m_signal_write); // wait for VM_SRV_SPP_EVENT_READY_TO_WRITE
        APP_LOG((char*)"LBTClientClass::write wait ok");
    }
    m_post_write = 0;
    vm_signal_clean(m_signal_write);

    remoteCall(btClientWrite, (void*)&c);
    m_post_write = 1;

	return c.lenProcessed;
}

LBTRingBuffer LBTClient_rx_buffer;
LBTClientClass LBTClient(&LBTClient_rx_buffer);


