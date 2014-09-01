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


#ifndef _LINKITDateTime_h
#define _LINKITDateTime_h

//datetimeInfo struct
typedef struct
{
	int year;//year
	int mon;//month,begin from 1
	int day;//day,begin from 1
	int hour;//hour,24-hour
	int min;//minute
	int sec;//second
}datetimeInfo;

// LDatetimeClass is designed to get system time related function
class LDateTimeClass
{
    
// Constructor / Destructor  
public:
	LDateTimeClass();

// Method
public:

	// Return current system time 
	//
	// RETURNS
	// if succeed, return 0, otherwise return -1
	//
	// EXAMPLE
	//	<code>
	//	#include <LDateTime.h>
	//  datetimeInfo t;
	//  unsigned int rtc;
	//	void setup()
	//  {
	//    
	//  }
	//	void loop()
	//  {
	//    LDateTime.getTime(&t);
	//    LDateTime.getRtc(&rtc);
	//    delay(1000);
	//  }
	//	</code> 
	int getTime(
		datetimeInfo *time	// [OUT] vm_time_t structure
		); 
	
	// Set system time 
	//
	// RETURNS
	// if succeed, return 0, otherwise return -1
	//
	// EXAMPLE
	//	<code>
	//	#include <LDateTime.h>
	//  datetimeInfo t;
	//	void setup()
	//  {
	//    
	//  }
	//	void loop()
	//  {
	//    LDateTime.getTime(&t);
	//    delay(1000);
	//  }
	//	</code> 
	int setTime(
		datetimeInfo *time	// [OUT] vm_time_t structure
		); 

	// Get the time since the Epoch (00:00:00 UTC, January 1, 1970),
	// measured in seconds.
	//
	// RETURNS
	// if succeed, return 0, otherwise failure.
	//
	// EXAMPLE
	//	<code>
	//	#include <LDateTime.h>
	//  datetimeInfo t;
	//  unsigned int rtc;
	//	void setup()
	//  {
	//    
	//  }
	//	void loop()
	//  {
	//    LDateTime.getTime(&t);
	//    LDateTime.getRtc(&rtc);
	//    delay(1000);
	//  }
	//	</code> 
	int getRtc(
		unsigned int *rtc	// [OUT] point to the time in seconds.
		);
};

//LDateTime object
extern LDateTimeClass LDateTime;

#endif

