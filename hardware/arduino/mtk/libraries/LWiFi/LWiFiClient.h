#ifndef LWiFiClient_h
#define LWiFiClient_h
#include "Arduino.h"
#include <LTcpClient.h>
#include <vmconn.h>
#include <vmtcp.h>

//LWiFiClient Class
class LWiFiClient : public LTcpClient
{
public:
  LWiFiClient();

  /* DOM-NOT_FOR_SDK-BEGIN */
  LWiFiClient(const LTcpClient &rhs);
  LWiFiClient(VMINT handle);
  LWiFiClient(VMINT handle, VMINT serverHandle);
  /* DOM-NOT_FOR_SDK-END */
};

#endif  // LWiFiClient_h
