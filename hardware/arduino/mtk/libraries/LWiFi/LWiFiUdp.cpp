#include <Arduino.h>
#include "LWiFiUdp.h"
#include "LWiFi.h"
#include "vmtcp.h"

VMINT LWiFiUDP::getAPN() const
{
  return VM_TCP_APN_WIFI;
}

int LWiFiUDP::beginPacket(const char *host, uint16_t port)
{
  // DNS loopup and bypass to IP version
  if (LWiFi.hostByName(host, m_sendToIP))
  {
    return beginPacket(m_sendToIP, port);
  }
  else
  {
    return 0;
  }
}

