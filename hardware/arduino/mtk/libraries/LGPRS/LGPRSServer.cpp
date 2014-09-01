#include "LGPRSServer.h"
#include <vmconn.h>
#include <vmtcp.h>
#include "LGPRS.h"

LGPRSServer::LGPRSServer(uint16_t port):
  LTcpServer(port)
{
  m_apn = LGPRS.getAPN();
}

LGPRSClient LGPRSServer::available()
{
	VMINT hClient = -1;
	VMINT hServer = -1;
	availableImpl(hClient, hServer);
	// return a special client object that has server handle
	// Note that we rely on move-constructor optimization
	// to prevent temp object destructor, which stop() the connection.
	return LGPRSClient(hClient, hServer);
}