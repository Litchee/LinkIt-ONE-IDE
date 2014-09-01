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
#ifndef _LGPS_H
#define _LGPS_H

#include "LTask.h"

#define GPS_MAX_GPGGA_SENTENCE_LENGTH 100
#define GPS_MAX_GPGSA_SENTENCE_LENGTH 80
#define GPS_MAX_GPRMC_SENTENCE_LENGTH 100
#define GPS_MAX_GPVTG_SENTENCE_LENGTH 80
#define GPS_MAX_GPGSV_SENTENCE_LENGTH 400
#define GPS_MAX_GLGSV_SENTENCE_LENGTH 400
#define GPS_MAX_BDGSV_SENTENCE_LENGTH 400
#define GPS_MAX_BDGSA_SENTENCE_LENGTH 80
#define GPS_MAX_GLGSA_SENTENCE_LENGTH 80

// gps sentence infomation
typedef struct
{
    unsigned char  GPGGA[GPS_MAX_GPGGA_SENTENCE_LENGTH+1];   // data of GPGGA
    unsigned char  GPGSA[GPS_MAX_GPGSA_SENTENCE_LENGTH+1];    // data of GPGSA
    unsigned char  GPRMC[GPS_MAX_GPRMC_SENTENCE_LENGTH+1];   // data of GPRMC
    unsigned char  GPVTG[GPS_MAX_GPVTG_SENTENCE_LENGTH+1];   // data of GPVTG
    unsigned char  GPGSV[GPS_MAX_GPGSV_SENTENCE_LENGTH+1];   // data of GPGSV
    unsigned char  GLGSV[GPS_MAX_GLGSV_SENTENCE_LENGTH+1];   // data of GLGSV
    unsigned char  GLGSA[GPS_MAX_GLGSA_SENTENCE_LENGTH+1];   // data of GLGSA
    unsigned char  BDGSV[GPS_MAX_BDGSV_SENTENCE_LENGTH+1];   // data of BDGSV
    unsigned char  BDGSA[GPS_MAX_BDGSA_SENTENCE_LENGTH+1];   // data of BDGSA
} gpsSentenceInfoStruct;

// gps mode
typedef enum
{
    GPS_START_MODE_NULL,
    GPS_HOT_START,               // GPS selects this mode when it remembers its last calculated position and the last recorded satellites is still in view. If you are at same location when the GPS was turned off, the GPS is capable of positioning in the shortest time.
    GPS_WARM_START,           // GPS selects this mode when it remembers its last calculated position but the last recorded satellites is not in view. The GPS then needs more time to locate the satellites and position.
    GPS_COLD_START,             // GPS selects this mode when it only has the current time. It takes longer time to locate the GPS information.
    GPS_FULL_START,              // GPS selects this mode when it has no information. There will be a full restart and it will take the longest time.
    GPS_START_TYPE_END
}gpsModeEnum;

/*gps type */
typedef enum
{
    GPS_ONLY,		/* GPS_ONLY */
    GPS_GLONASS,	/* GPS+GLONASS */
    GPS_BEIDOU,		/* GPS+BEIDOU */
    GPS_TYPE_END
} gpsTypeEnum;

// LGPS class interface, With this library, you can get GPS data. Basic flow of controlling GPS:
class LGPSClass  : public _LTaskClass {

// Constructor / Destructor
public:
	LGPSClass() { };

// Method
public:
	 // DESCRIPTION
	 //     Turns on GPS device.
	 // RETURNS
	 //     N/A
	 // EXAMPLE
	 //  <code>
	 //  #include <LGPS.h>
	 //  gpsSentenceInfoStruct info;
        //  void setup()
	 //  {
	 //     LGPS.powerOn();
	 //     delay(500);
	 //     LGPS.setMode(GPS_HOT_START);
	 //  }
	 //  void loop()
	//  {
	//     LGPS.getData(&info);
	//     delay(2000);
	//  }
	//  </code>
	void powerOn(gpsTypeEnum type = GPS_GLONASS);

	 // DESCRIPTION
	 //     Turns off GPS.
	 //     Note: Turning off GPS when GPS data are not required can save power.
	 // RETURNS
	 //     N/A
	void powerOff(void);

	 // DESCRIPTION
	 //    Sets up GPS start mode.
	 // RETURNS
	 //    N/A
	void setMode(
			gpsModeEnum mode    // [IN] please refer the enum gpsModeEnum
		);

	 // DESCRIPTION
	 //    get GPS data
	 // RETURNS
	 //    N/A
	void getData(
			gpsSentenceInfoStruct* info    // [IN] please refer the struct gpsSentenceInfoStruct
			);
	
public:
	void setData(gpsSentenceInfoStruct* info);

private:
	gpsSentenceInfoStruct m_info;

};

extern LGPSClass LGPS;

#endif
