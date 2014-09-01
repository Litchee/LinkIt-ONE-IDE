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
#include "vmmm.h"
#include "vmchset.h"
#include "LAudio.h"
#include "Audio.h"
#include "vmlog.h"
#include "vmio.h"
#include "vmstdlib.h"

typedef void (*call_func_ptr)(int result);
call_func_ptr g_callback = NULL;


void audio_callback(VMINT result)
{
	if(g_callback)
		g_callback(result);
	return;
}

boolean audioPlay(void* user_data)
{
  VMWCHAR path[256];
  VMCHAR path_a[256];

  VMINT drv ;
  VMCHAR driver_str[2] = {0};

  if(LAudio.getDriver() ==0)
  {
  	drv = vm_get_system_driver();
  }
  else
  {
  	drv = vm_get_removable_driver();
  }
  
  if(drv >=0)
  {
	
	if( LAudio.getType())
	{
  	    sprintf(path_a,"%c:\\%s", drv, LAudio.getFile());
	    vm_ascii_to_ucs2(path, 256, path_a);
	}
	else
	{
		sprintf(path_a,"%c:\\", drv);
		vm_ascii_to_ucs2(path, 256, path_a);
		vm_wstrcat(path, (VMWSTR)LAudio.getFile());
	}
  }
  else
  {
  	vm_log_info("AudioPlay get driver error");
	return true;
  }
  

  
  g_callback = (call_func_ptr)user_data;
  vm_audio_play_file(path, audio_callback);
  vm_set_volume(LAudio.getVolume());
  return true;
}

boolean audioPause(void* user_data)
{
  vm_audio_pause(audio_callback);
  return true;
}

boolean audioResume(void* user_data)
{
  vm_audio_resume(audio_callback);
  return true;
}

boolean audioStop(void* user_data)
{
  vm_audio_stop(audio_callback);
  return true;
}

boolean audioSetVolume(void* user_data)
{
  vm_set_volume(LAudio.getVolume());
  return true;
}


