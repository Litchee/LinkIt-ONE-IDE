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


#ifndef _LINKITGSM_h
#define _LINKITGSM_h

#include <Arduino.h>
#include "LTask.h"

#define LGSM_MAX_SMS_LEN    500

// Class of LinkIt SMS support 
class LSMSClass : public Stream
{
// Constructor / Destructor    
public:
    LSMSClass(void);
    ~LSMSClass(void);

// Method
public:
    using Print::write; // pull in write(str) and write(buf, size) from Print

	// DESCRIPTION
	//  Step two of sending an SMS: Write one byte at a time into the SMS content.
    //  You can also use print() to write a string into SMS content at a time.
	// RETURNS
	//  1: Succeed, 0: Fail
    size_t write(
        uint8_t c   // [IN] byte to write
    );

	// DESCRIPTION
	//  Step one of sending an SMS: Input the destination number.
	// RETURNS
	//  1: Succeed, 0: Fail
    int beginSMS(
        const char* to  // [IN] SMS destination number 
    );

	// DESCRIPTION
	//  Checks if SMS module is ready or not.
	// RETURNS
	//  1 if ready, 0 if not
    int ready();

	// DESCRIPTION
	//  The last step of sending an SMS: Confirm and send out the SMS.
	// RETURNS
	//  1: Sending succeeds. 0: Send fails.
    int endSMS();

	// DESCRIPTION
	//  Checks if there is any unread SMS.
	// RETURNS
	//  1: There is unread SMS. 0: There is no unread SMS.
    int available();

	// DESCRIPTION
	//  Returns the source number of the unread SMS.
 	// RETURNS
	//  Length of the returning SMS number 
    //  If there is no unread SMS, it will return 0.
    //  If the size of input array is too small, it will return the required size without filling the input array. Please call again with larger array.
    int remoteNumber(
        char* number,   // [OUT] array to save SMS number
        int nlength     // [IN] size of the array
    ); 

	// DESCRIPTION
	//  Reads the content of the unread SMS, one byte at a time.
    //  The difference between read() and peek() is that read() moves the cursor but peak() does not.
	// RETURNS
	//  One byte of SMS content. Will be -1 if it reaches the end of SMS.
    int read();

	// DESCRIPTION
	//  Reads the content of the unread SMS, one byte at a time without moving the cursor.
    //  Repeatedly calling peek() will return the same result.
	// RETURNS
	//  One byte of SMS content. Will be -1 if it reaches the end of SMS.
    int peek();

	// DESCRIPTION
	//  Deletes the unread SMS.
    //  It only works when there is unread SMS checked by available().
    void flush();

private:

    // member for write SMS
    String _toNumber;   // maximum length for TP-DA/OA should be 12 octets (14 chars)
    String _toContent;

    // member for read SMS
    int _msgId;         // current SMS id
    char *_msgNumber;   // number data of current SMS
    char *_msgContent;  // content data of current SMS

    int _msgPos;        // current position of content (for sequential read/peak)

    
};

extern LSMSClass LSMS;

enum LVoiceCall_voiceCall_st { IDLE_CALL, CALLING, RECEIVINGCALL, TALKING};

// Class of LinkIt Voice call support 
class LVoiceCallClass : public _LTaskClass
{
// Constructor / Destructor    
public:
    LVoiceCallClass(void);
    ~LVoiceCallClass(void);

// Method
public:

	// DESCRIPTION
	//  Check if the previous voice operation has executed successfully
	// RETURNS
	//  1: if previous operation executed successfully. 0: if not.
    int ready();

	// DESCRIPTION
	//  Make a voice call to a specified number
	// RETURNS
	//  1: Callout succeed, 0: Fail
    int voiceCall(
        const char* to,  // [IN] The number to call.
        unsigned long timeout=30000 // [IN] timeout count
    );

	// DESCRIPTION
	//  Checks status of the voice call.
	// RETURNS
	//  0 IDLE_CALL, 1 CALLING, 2 RECEIVINGCALL, 3 TALKING
    char getVoiceCallStatus(void);

	// DESCRIPTION
	//  Accepts an incoming voice call.
	// RETURNS
	//  1: Answer succeeds. 0: Answer fails.
    int answerCall(void);


	// DESCRIPTION
	//  Retrieves the calling number.
 	// RETURNS
	//  1: Retrieve succeeds. 0: Retrieve fails.
    int retrieveCallingNumber(
        char* number,   // [OUT] array to save call number
        int nlength     // [IN] size of the array
    ); 

	// DESCRIPTION
	//  Hang up an established call or during incoming rings. 
	// RETURNS
	//  1: Hang succeeds. 0: Hang fails.
    int hangCall(void);

private:

    
};

extern LVoiceCallClass LVoiceCall;

#undef LINKITGSM_DEBUG

#ifdef LINKITGSM_DEBUG
#define LGSMLOG(x) Serial.println(x)
#else
#define LGSMLOG(x)  
#endif

#endif

