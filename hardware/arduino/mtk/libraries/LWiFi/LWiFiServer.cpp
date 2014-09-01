#include "LWiFiServer.h"
#include <vmconn.h>
#include <vmtcp.h>

LWiFiServer::LWiFiServer(uint16_t port):
    LTcpServer(port)
{
  m_apn = VM_TCP_APN_WIFI;
}

LWiFiClient LWiFiServer::available()
{
  VMINT hClient = -1;
  VMINT hServer = -1;
  availableImpl(hClient, hServer);
  // return a special client object that has server handle
  // Note that we rely on move-constructor optimization
  // to prevent temp object destructor, which stop() the connection.
  return LWiFiClient(hClient, hServer);
}
