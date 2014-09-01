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
#include "vmtel.h"
#include "vmlog.h"
#include "LGSM.h"
#include "vmchset.h"
#include "string.h"
#include "VoiceCall.h"

extern vm_call_listener_func g_call_status_callback;

static vm_ucm_id_info_struct g_uid_info;
static int g_call_status = IDLE_CALL;
static char g_number[42];

static void __call_listener_func(vm_call_listener_data* data)
{
    if(data->type_op == VM_UCM_INCOMING_CALL_IND)
    {
    	vm_ucm_incoming_call_ind_struct* ind = (vm_ucm_incoming_call_ind_struct*)data->data;
	g_uid_info.call_id = ind->uid_info.call_id;
	g_uid_info.group_id = ind->uid_info.group_id;
	g_uid_info.call_type = ind->uid_info.call_type;
	strcpy(g_number, (char*)ind->num_uri);
	g_call_status = RECEIVINGCALL;		
    }
    else if(data->type_op == VM_UCM_OUTGOING_CALL_IND)
    {
    	vm_ucm_outgoing_call_ind_struct* ind = (vm_ucm_outgoing_call_ind_struct*)data->data;
	g_uid_info.call_id = ind->uid_info.call_id;
	g_uid_info.group_id = ind->uid_info.group_id;
	g_uid_info.call_type = ind->uid_info.call_type;
	strcpy(g_number, (char*)ind->num_uri);
	g_call_status = TALKING;
    }
    else if(data->type_op == VM_UCM_CALL_END)
    {
        g_call_status = IDLE_CALL;
    }
    else
    {
    	vm_log_info("bad operation type");
    }
}

void registerCallback(void)
{
    g_call_status_callback = __call_listener_func;
}

static void _call_voiceCall_callback(vm_call_actions_callback_data* data)
{
   VMINT* result = (VMINT*)data->userdata;

   if(data->type_act == VM_UCM_DIAL_ACT)
    {
	
    	if(data->data_act_rsp.result_info.result == VM_UCM_RESULT_OK)
	{
		*result = 1;
		g_call_status = CALLING;
		LVoiceCall.post_signal();
    	}
	else
	{
		*result = 0;
		g_call_status = IDLE_CALL;
	}
    }
    else if(data->type_act == VM_UCM_ACCEPT_ACT)
    {
    	if(data->data_act_rsp.result_info.result == VM_UCM_RESULT_OK)
	{
		*result = 1;
		g_call_status = TALKING;
		LVoiceCall.post_signal();
    	}
	else
	{
		*result = 0;
		g_call_status = IDLE_CALL;
	}
    }
    else if(data->type_act == VM_UCM_HOLD_ACT)
    {
    	// not use
    }
    else if(data->type_act == VM_UCM_END_SINGLE_ACT)
    {
       *result = 1;
	LVoiceCall.post_signal();
	g_call_status = IDLE_CALL;
    }
    else
    {
    	// not use
    }
}

boolean callvoiceCall(void* user_data)
{
  VMINT ret;
  call_info_struct* callInfo_p = (call_info_struct*)user_data;
  vm_ucm_dial_act_req_struct req;
  vm_call_actions_data data;
  
  req.call_type = VM_UCM_VOICE_CALL_TYPE;
  req.is_ip_dial = 0;
  req.module_id = 0;
  vm_ascii_to_ucs2((VMWSTR)req.num_uri, VM_UCM_MAX_NUM_URI_LEN, (VMSTR)callInfo_p->num);

  req.phb_data = NULL;

  data.type_act = VM_UCM_DIAL_ACT;
  data.data_act = (void*)&req;
  data.userdata = (void*)&callInfo_p->result;
  data.callback = _call_voiceCall_callback;
  
  ret = vm_call_actions(&data);
  
  if(ret == 0)
  {
  	return false;
  }
  else
  {
  	callInfo_p->result = 0;
  	return true;
  }
}

boolean callanswerCall(void* user_data)
{
  VMINT ret;
  VMINT* result = (VMINT*)user_data;
  vm_ucm_single_call_act_req_struct req;
  vm_call_actions_data data;
  
  req.action_uid.call_type   = g_uid_info.call_type;
  req.action_uid.call_id = g_uid_info.call_id;
  req.action_uid.group_id = g_uid_info.group_id;

  data.type_act = VM_UCM_ACCEPT_ACT;
  data.data_act = (void*)&req;
  data.userdata = result;
  data.callback = _call_voiceCall_callback;
  ret = vm_call_actions(&data);
  
  if(ret == 0)
  {
  	return false;
  }
  else
  {
  	*result = 0;
  	return true;
  }
}

boolean callretrieveCallingNumber(void* user_data)
{
  call_info_struct* callInfo =  (call_info_struct*)user_data;
  callInfo->result = 0;

  if(g_call_status == RECEIVINGCALL || g_call_status == TALKING)
  {
  	strcpy((char*)callInfo->num, (char*)g_number);
	callInfo->result = 1;
  }
  
  return true;
}

boolean callready(void* user_data)
{
  VMINT* result = (VMINT*)user_data;
  *result = 1;
  return true;
}

boolean callgetVoiceCallStatus(void* user_data)
{
  char* status = (char*)user_data;
  *status = g_call_status;
  return true;
}

boolean callhangCall(void* user_data)
{
  VMINT ret;
  VMINT* result = (VMINT*)user_data;
  vm_ucm_single_call_act_req_struct req;
  vm_call_actions_data data;
  
  if(IDLE_CALL == g_call_status)
  	return true;
  
  req.action_uid.call_type   = g_uid_info.call_type;
  req.action_uid.call_id = g_uid_info.call_id;
  req.action_uid.group_id = g_uid_info.group_id;

  data.type_act = VM_UCM_END_SINGLE_ACT;
  data.data_act = (void*)&req;
  data.userdata = user_data;
  data.callback = _call_voiceCall_callback;
  ret = vm_call_actions(&data);
  /*
  if(ret == 0)
  {
  	return false;
  }
  else
  */
  {
  	*result = 1;
  	return true;
  }
}



