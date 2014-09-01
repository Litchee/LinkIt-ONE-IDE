#ifndef LGPRSServer_h
#define LGPRSServer_h
#include <Arduino.h>
#include <LTcpServer.h>
#include "LGPRSClient.h"

//LGPRSServer Class
class LGPRSServer : public LTcpServer {
public:
  LGPRSServer(uint16_t port);
  LGPRSClient available();
};

#endif