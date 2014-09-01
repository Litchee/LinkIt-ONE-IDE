#include "LGPRSClient.h"
#include <vmconn.h>
#include <vmtcp.h>
#include "LGPRS.h"

LGPRSClient::LGPRSClient():
  LTcpClient()
{
  m_apn = LGPRS.getAPN();
}

LGPRSClient::LGPRSClient(const LTcpClient &rhs):
  LTcpClient(rhs)
{
  m_apn = LGPRS.getAPN();
}

LGPRSClient::LGPRSClient(VMINT handle):
  LTcpClient(handle)
{
  m_apn = LGPRS.getAPN();
}

LGPRSClient::LGPRSClient(VMINT handle, VMINT serverHandle):
  LTcpClient(handle, serverHandle)
{
  m_apn = LGPRS.getAPN();
}