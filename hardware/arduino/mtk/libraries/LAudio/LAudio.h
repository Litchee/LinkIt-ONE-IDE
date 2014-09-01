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
#ifndef _LAUDIO_H
#define _LAUDIO_H

#include "chip.h"
#include "vmsys.h"
#include "LTask.h"
#include "arduino.h"

// playing status
typedef enum 
{
	AudioCommonFailed = -1,     // Playback fails (e.g. the audio file is corrupted).
	AudioStop = 1,                       // Playback is stopped.
	AudioPause = 2,                     // Playback is paused (and can resume).
	AudioResume = 3,                  // Playback resumes
	AudioEndOfFile = 5               // Playback is finished.
}AudioStatus;

// storage location
typedef enum 
{
	storageFlash,    // Flash
	storageSD         // SD
}StorageEnum;

// LAudio class interface
class LAudioClass  : public _LTaskClass {

// Constructor / Destructor
public:
	LAudioClass() { };

public:	
	 // DESCRIPTION
	 //    Plays an audio file on SD card or flash storage.
	 // RETURNS
	 //    N/A
	 // EXAMPLE
	 //  	<code>
	//	#include <LAudio.h>  
	//	void setup()
	//	{
	//   	    LAudio.begin();
	//   	    LAudio.playFile(storageFlash, (char*)"sample.mp3");
	//   	    LAudio.setVolume(2);
	//   	    delay(2000);
	//   	    LAudio.pause();
	//   	    delay(2000);
	//   	    LAudio.resume();
	//   	    delay(2000);
	//   	    LAudio.stop();
	//	}	
	//  	</code>
	void    playFile(
			StorageEnum drv,        // [IN] Storage, can be storageSD (SD card) or storageFlash (flash storage)
			char *songName         // [IN]  Path of audio file in ascii (char*) 
			);
	
	 // DESCRIPTION
	 //    Plays an audio file on SD card or flash storage.
	 // RETURNS
	 //    N/A
	void    playFile(
			StorageEnum drv,        // [IN] Storage, can be storageSD (SD card) or storageFlash (flash storage)
			wchar_t* songName        // [IN] Path of audio file in unicode (wchar_t*) encoding
			);

	 // DESCRIPTION
	 //    Adjusts the playback volume; range is from 0 (silent) to 6 (max).
	 // RETURNS
	 //    N/A
	void    setVolume(
			unsigned char volume       // [IN] Volume level, can be 0 to 6; 0 as silent and 6 as max volume
			);

	 // DESCRIPTION
	 //    Pauses the playback. It only works when there is an active playback ongoing (by playFile()).
	 // RETURNS
	 //    N/A
	void    pause(void);

	 // DESCRIPTION
	 //    Resumes playback. It only works when the playback has been paused.
	 // RETURNS
	 //    N/A
	void    resume(void);

	 // DESCRIPTION
	 //    Stops playback.
	 // RETURNS
	 //    N/A
	void    stop(void);

	 // DESCRIPTION
	 //    Queries the current playback status.
	 // RETURNS
	 //    AudioStatus: Playback status, can be:
	 //    AudioStop: Playback is stopped.
	 //    AudioPause: Playback is paused (and can resume).
	 //    AudioResume: Playback resumes
	 //    AudioEndOfFile: Playback is finished.
	 //    AudioCommonFailed: Playback fails (e.g. the audio file is corrupted).
	AudioStatus    getStatus(void);
	
public:
	VMSTR getFile();
	char getDriver();
	boolean getType();
	unsigned char getVolume();
	static void onCallback(int result);
private:
	char m_path[256];
	unsigned char  m_volume;
	char m_drv;
	boolean m_type;
};

extern LAudioClass LAudio;

#endif
