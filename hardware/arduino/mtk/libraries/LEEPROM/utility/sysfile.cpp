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
#include "vmio.h"
#include "vmlog.h"
#include "sysfile.h"
#include "LEEPROM.h"

#define APP_LOG(...) vm_log_info(__VA_ARGS__); \
    Serial.println(__VA_ARGS__)
fs_data_t g_fs_data;


boolean onRead(void* user_data)
{
    VMINT hdl, ret;
    fs_data_t *tmp_fs_data = (fs_data_t*)&g_fs_data;
    VMUINT read = 0;

    APP_LOG((char*)"EEPROM onRead -s");
    if (0 > tmp_fs_data->addr)
    {
        setReadData(0);
        APP_LOG((char*)"EEPROM fs_data->addr[%d] -e1", tmp_fs_data->addr);
        return true;
    }
    
    hdl = vm_sys_file_open(MODE_READ, 1);
    if (0 > hdl)
    {
        setReadData(0);
        APP_LOG((char*)"EEPROM hdl[%d] -e2", hdl);
        return true;
    }

    ret = vm_sys_file_seek(hdl, tmp_fs_data->addr, BASE_BEGIN);
    APP_LOG((char*)"EEPROM vm_sys_file_seek [%d][%d]", tmp_fs_data->addr, ret);

    ret = vm_sys_file_read(hdl, &(tmp_fs_data->value), 1, &read);
    APP_LOG((char*)"EEPROM vm_sys_file_read [%d][%d] v[%d]", read, ret, tmp_fs_data->value);
    
    setReadData(tmp_fs_data->value);

    vm_sys_file_close(hdl);
    
    APP_LOG((char*)"EEPROM onRead -e");
    return true;   
}
boolean onWrite(void* user_data)
{
    VMINT hdl, ret;
    fs_data_t *tmp_fs_data = (fs_data_t*)&g_fs_data;
    VMUINT written = 0;
    
    APP_LOG((char*)"EEPROM onWrite -s");
    if (0 > tmp_fs_data->addr)
    {
        setReadData(0);
        APP_LOG((char*)"EEPROM fs_data->addr[%d] -e1", tmp_fs_data->addr);
        return true;
    }
    
    hdl = vm_sys_file_open(MODE_WRITE, 1);
    if (0 > hdl)
    {
        hdl = vm_sys_file_open(MODE_CREATE_ALWAYS_WRITE, 1);
        if (0 > hdl)
        {
            APP_LOG((char*)"EEPROM MODE_CREATE_ALWAYS_WRITE FAILED");
            return true;
        }
        APP_LOG((char*)"EEPROM MODE_CREATE_ALWAYS_WRITE OK");
    }

    APP_LOG((char*)"EEPROM vm_sys_file_open [%d]", hdl);

    ret = vm_sys_file_seek(hdl, tmp_fs_data->addr, BASE_BEGIN);
    APP_LOG((char*)"EEPROM vm_sys_file_seek [%d][%d]", tmp_fs_data->addr, ret);

    ret = vm_sys_file_write(hdl, &(tmp_fs_data->value), 1, &written);
    APP_LOG((char*)"EEPROM vm_sys_file_write [%d][%d] v[%d]", written, ret, tmp_fs_data->value);
    
    setReadData(tmp_fs_data->value);

    vm_sys_file_close(hdl);
    
    APP_LOG((char*)"EEPROM onWrite -e");
    return true;   
}

// be called in arduino task.
VMUINT8 getReadData()
{
    APP_LOG((char*)"getReadData [%d]", g_fs_data.value);
    return g_fs_data.value;
}

// mmi task set data
void setReadData(VMUINT8 data_read)
{
    g_fs_data.value = data_read;
    APP_LOG((char*)"setReadData [%d]", data_read);
}


