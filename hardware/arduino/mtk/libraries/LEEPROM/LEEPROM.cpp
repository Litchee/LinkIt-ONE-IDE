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
#include "LEEPROM.h"
#include "sysfile.h"
#include "vmlog.h"
#define APP_LOG(...) vm_log_info(__VA_ARGS__); \
    Serial.println(__VA_ARGS__)

//extern void app_log_file(char *fmt, ...);


LEEPROMClass::LEEPROMClass(int init) : _LTaskClass(), m_init(init)
{
    //Serial.println("LEEPROMClass::LEEPROMClass");
    //APP_LOG((char*)"LEEPROMClass::LEEPROMClass");
    //_LTaskClass::begin();
    //APP_LOG((char*)"LEEPROMClass::LEEPROMClass");
}

/*

LEEPROMClass::~LEEPROMClass()
{
    //APP_LOG((char*)"LEEPROMClass::~LEEPROMClass");
    //_LTaskClass::stop();
    //APP_LOG((char*)"LEEPROMClass::~LEEPROMClass");
}
*/
VMUINT8 LEEPROMClass::read(int addr)
{
    APP_LOG((char*)"LEEPROMClass::read [%d]", addr);
    if (!m_init)
    {
        _LTaskClass::begin();    
        m_init = 1;
    }

    if (0 > addr || 1024 <= addr)
    {
        APP_LOG((char*)"LEEPROMClass::read e1");
        return 0;
    }
    g_fs_data.addr = addr;
    APP_LOG((char*)"remoteCall onRead s");
	remoteCall(onRead, (void*)NULL);
    APP_LOG((char*)"remoteCall onRead e");
	return getReadData();
}

void LEEPROMClass::write(int addr, uint8_t value)
{
    APP_LOG((char*)"LEEPROMClass::write @[%d] value[%d]", addr, value);
    if (!m_init)
    {
        _LTaskClass::begin();    
        m_init = 1;
    }

    if (0 > addr || 1024 <= addr)
    {
        APP_LOG((char*)"LEEPROMClass::write e1");
        return;
    }
    g_fs_data.addr = addr;
    g_fs_data.value = value;
    APP_LOG((char*)"remoteCall onWrite s");
	remoteCall(onWrite, (void*)NULL);
    APP_LOG((char*)"remoteCall onWrite e");
    //return 0;
}

LEEPROMClass & getEEPROM(void)
{
    
    static LEEPROMClass EEPROM_internal(0);
    return EEPROM_internal;
}

