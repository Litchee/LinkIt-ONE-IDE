#ifndef LGPRS_h
#define LGPRS_h

#include "Arduino.h"
#include "IPAddress.h"
#include "vmnwsetting.h"
#include "vmconn.h"

class LGPRSConnectContext;

//LGPRS Class
class LGPRSClass
{
public:

	/* DOM-NOT_FOR_SDK-BEGIN */
    LGPRSClass();
    /* DOM-NOT_FOR_SDK-END */	

    // DESCRIPTION
    //  Sets up the Access Point Name (APN) information used to connect to GPRS network. Use the data provided by your telecom operator to set it up
    // 
    // PARAMETERS
    //  APNName: char array, Access Point Name (APN) provided by the telecom operator
    //  userName: char array, user name, provided by the telecom operator. Pass NULL if the telecom operator does not provide the username information.
    //  password: char array, password provided by the telecom operator. Pass NULL if the telecom operator does not provide the password information.
    //
    // RETURN
    //  1: APN setup succeeded
    //  0: Otherwise
    int attachGPRS(const char *apn, const char *username, const char *password);

    // DESCRIPTION
    //  Automatically detect Access Point Name (APN) information from SIM card and use it to connect to GPRS network.
    // 
    // PARAMETERS
    //  APNName: char array, Access Point Name (APN) provided by the telecom operator
    //  userName: char array, user name, provided by the telecom operator. Pass NULL if the telecom operator does not provide the username information.
    //  password: char array, password provided by the telecom operator. Pass NULL if the telecom operator does not provide the password information.
    //
    // RETURN
    //  1: APN setup succeeded
    //  0: Otherwise
    int attachGPRS();

    // DESCRIPTION
    //  Queries the IP address of the LinkIt device after connecting to GPRS network through LGPRS.attachGPRS().
    // 
    // PARAMETERS
    //  N/A
    //
    // RETURN
    //  The IP address dispatched by the GPRS network. The value is meaningless before LGPRS.attachGPRS() succeeds.
    IPAddress localIP();

    // DESCRIPTION
    //  Resolve the given hostname to an IP address.
    // 
    // PARAMETERS
    //  param aHostname: Name to be resolved
    //  param aResult: IPAddress structure to store the returned IP address
    // 
    // RETURNS
    //  1 if aIPAddrString was successfully converted to an IP address, 
    //  else error code
    int hostByName(const char* aHostname, IPAddress& aResult); 

    VMINT getAPN() const;
    friend class LGPRSServer;
    friend class LGPRSClient;
    
private:
    boolean m_simCardReady;
    boolean m_customAPN;
    static boolean gprsCheckSIM(void *userData);
};

extern LGPRSClass LGPRS;

#endif // #ifndef LGPRS_h