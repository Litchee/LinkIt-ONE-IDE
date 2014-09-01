#include "LWiFiClient.h"
#include <vmconn.h>
#include <vmtcp.h>

#if 1
LWiFiClient::LWiFiClient():
    LTcpClient()
{
  m_apn = VM_TCP_APN_WIFI;
}

LWiFiClient::LWiFiClient(const LTcpClient &rhs):
    LTcpClient(rhs)
{
  m_apn = VM_TCP_APN_WIFI;
}

LWiFiClient::LWiFiClient(VMINT handle):
    LTcpClient(handle)
{
  m_apn = VM_TCP_APN_WIFI;
}

LWiFiClient::LWiFiClient(VMINT handle, VMINT serverHandle):
    LTcpClient(handle, serverHandle)
{
  m_apn = VM_TCP_APN_WIFI;
}
#endif
