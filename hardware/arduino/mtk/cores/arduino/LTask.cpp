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
#include "vmsys.h"
#include "vmthread.h"
#include "LTask.h"
#include "arduino.h"


_LTaskClass::_LTaskClass()
{
	m_handle = 0;
	m_signal = 0;
}

void _LTaskClass::begin(void)
{
	vm_mutex_create(&m_mutex);
	m_handle = vm_thread_get_main_handle();
	m_signal = vm_signal_init();
}

void _LTaskClass::sendMsg(VMUINT32 msg_id, void* user_data)
{
	if(m_handle == 0)
	{
		begin();
	}
	if(m_handle != 0)
	{
		vm_thread_send_msg(m_handle, msg_id, user_data);
	}
}

void _LTaskClass::stop(void)
{
	m_handle = 0;
	vm_signal_clean(m_signal);
	vm_signal_deinit(m_signal);
	m_signal = 0;
}

void _LTaskClass::mutexLock()
{
	if(m_handle == 0)
	{
		begin();
	}
	
	vm_mutex_lock(&m_mutex);
}

void _LTaskClass::mutexUnlock()
{
	if(m_handle == 0)
	{
		begin();
	}
	
	vm_mutex_unlock(&m_mutex);
}

void _LTaskClass::post_signal()
{
	if(m_handle == 0)
	{
		begin();
	}
	
	vm_signal_post(m_signal);
}

void _LTaskClass::remoteCall(remote_call_ptr func,  void* userdata)
{
		if(m_handle == 0)
		{
			begin();
		}
    mutexLock();
    m_msg.remote_func = (remote_call_ptr)func;
    m_msg.userdata = userdata;
    m_msg.signal = m_signal;
    sendMsg(VM_MSG_ARDUINO_CALL, &m_msg);
    vm_signal_wait(m_signal);
    mutexUnlock();
}

_LTaskClass LTask = _LTaskClass();

