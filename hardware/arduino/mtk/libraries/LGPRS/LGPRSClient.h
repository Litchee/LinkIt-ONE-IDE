#ifndef LGPRSClient_h
#define LGPRSClient_h
#include "Arduino.h"
#include <LTcpClient.h>
#include <vmconn.h>
#include <vmtcp.h>

//LGPRSClient Class
class LGPRSClient : public LTcpClient {
public:
  LGPRSClient();
  
  /* DOM-NOT_FOR_SDK-BEGIN */
  LGPRSClient(const LTcpClient &rhs);
  LGPRSClient(VMINT handle);
  LGPRSClient(VMINT handle, VMINT serverHandle);
  /* DOM-NOT_FOR_SDK-END */
};

#endif  // LGPRSClient_h