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
#include <string.h>
#include <wchar.h>
#include "vmsys.h"
#include "vmmm.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "LAudio.h"
#include "audio.h"

static int status_result = 0 ;

void LAudioClass::onCallback(int result) {
	status_result = result;
}

void LAudioClass::playFile(StorageEnum drv, char *songName)
{
	strcpy((char*)m_path, songName);
	m_drv = drv;
	m_type = true;
	remoteCall(audioPlay, (void*)this->onCallback);
}

void LAudioClass::playFile(StorageEnum drv, wchar_t* songName)
{
	wcscpy((wchar_t*)m_path, songName);
	m_drv = drv;
	m_type = false;
	remoteCall(audioPlay, (void*)this->onCallback);
}

void LAudioClass::setVolume(unsigned char volume){
	m_volume = volume;
       remoteCall(audioSetVolume, NULL);
}

void LAudioClass::pause(){
       remoteCall(audioPause, NULL);
}

void LAudioClass::resume(){
       remoteCall(audioResume, NULL);
}

void LAudioClass::stop(){
       remoteCall(audioStop, NULL);
}

AudioStatus LAudioClass::getStatus(){
      AudioStatus status = (AudioStatus)status_result;
      status_result = 0;
      return status;
}
	
VMSTR LAudioClass::getFile(){
	return m_path;
}

unsigned char LAudioClass::getVolume(){
	return m_volume;
}

char LAudioClass::getDriver()
{
	return m_drv;
}

boolean LAudioClass::getType()
{
	return m_type;
}

//void    setPlayMode(playMode_t playmode) { _playmode = playmode;}


LAudioClass LAudio;

