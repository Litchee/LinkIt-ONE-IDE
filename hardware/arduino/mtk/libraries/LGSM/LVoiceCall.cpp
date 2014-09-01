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
#include "LGSM.h"

#include <vmsim.h>
#include <vmchset.h>
#include <vmstdlib.h>
#include "VoiceCall.h"

/*****************************************************************************
* 
* LVoiceCallClass class
* 
*****************************************************************************/
LVoiceCallClass::LVoiceCallClass()
{
	registerCallback();
}

LVoiceCallClass::~LVoiceCallClass()
{

}

int LVoiceCallClass::ready()
{
	int result = 0;
	remoteCall(callready, (void*)&result);
	return result;
}

int LVoiceCallClass::voiceCall(const char* to,  unsigned long timeout)
{
	call_info_struct callInfo;
	strcpy(callInfo.num, to);
	remoteCall(callvoiceCall, (void*)&callInfo);
	return callInfo.result;
}

char LVoiceCallClass::getVoiceCallStatus(void)
{
    char status;
    remoteCall(callgetVoiceCallStatus, (void*)&status);
    return status;
}

int LVoiceCallClass::answerCall(void)
{
	int ret;
	remoteCall(callanswerCall, &ret);
	return ret;
}

int LVoiceCallClass::retrieveCallingNumber(char* number, int nlength )
{
	call_info_struct callInfo;
	
	memset(number, 0, nlength);

	remoteCall(callretrieveCallingNumber, (void*)&callInfo);
	
	if(callInfo.result == 1)
	{
		strcpy(number, callInfo.num);
		return 1;
	}
	else
	{
		return 0;
	}
}

int LVoiceCallClass::hangCall(void)
{
	int ret;
	remoteCall(callhangCall, (void*)&ret);
	return ret;
}

LVoiceCallClass LVoiceCall;

