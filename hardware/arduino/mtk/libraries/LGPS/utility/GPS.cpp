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
#include "vmgps.h"
#include "vmlog.h"
#include "GPS.h"
#include "LGPS.h"

typedef void (*vm_gps_handler_t)(vm_gps_sentence_info* info);
vm_gps_handler_t _gps_handle = NULL;

static void _gps_callback(VMINT msg, void* data)
{
     switch(msg)
     {
     case VM_GPS_OPEN_CNF:
         {
             VMINT result = (VMINT)data;
             if(result == true)
             {
                vm_log_info((char*)"open success");
             }
             else
             {
                 vm_log_warn((char*)"open failed");
             }
         }
         break;
     case VM_GPS_CLOSE_CNF:
         // app cannot receive this msg now, ignore this.
         break;
     case VM_GPS_SET_MODE_CNF:
         {
             VMINT result = (VMINT)data;
             if(result == true)
             {
             	  vm_log_info((char*)"set mode success");
             }
             else
	      {
             	  vm_log_warn((char*)"set mode failed");
             }
         }
         break;
     case VM_GPS_SENTENCE_DATA:
         {
            	LGPS.setData((gpsSentenceInfoStruct*)data);
         }
         break;
     }
 }

boolean gpsPowerOn(void* user_data)
{
  VMINT result;
  vm_gps_type_enum* type = (vm_gps_type_enum*)user_data;

  result = vm_gps_open( 1, *type, _gps_callback);
		     
  if(result == VM_GPS_OPEN_SUCCESS)
  {
      // this is first time to open GPS, need to get the message VM_GPS_OPEN_CNF
      vm_log_info((char*)"gps open success");
  }
  else if(result == VM_GPS_OPEN_ALREADY_OPEN)
  {
      // GPS had been opened before, can get data, no need to wait VM_GPS_OPEN_CNF
      // if need you can set mode
      // vm_gps_set_mode();
      vm_log_info((char*)"gps already open");

  }
  else
  {
      // open failed
      vm_log_info((char*)"gps open failed");
  }
  return true;
}

boolean gpsPowerOff(void* user_data)
{
  vm_gps_close();
  return true;
}

boolean gpsSetMode(void* user_data)
{
  vm_gps_mode_enum* mode = (vm_gps_mode_enum*)user_data;
  vm_gps_set_mode(*mode);
  return true;
}


