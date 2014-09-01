#ifndef LWifiServer_h
#define LWifiServer_h
#include <Arduino.h>
#include <LTcpServer.h>
#include "LWiFiClient.h"

//LWiFiServer Class
class LWiFiServer : public LTcpServer
{
public:
  LWiFiServer(uint16_t port);
  LWiFiClient available();
};

#endif
