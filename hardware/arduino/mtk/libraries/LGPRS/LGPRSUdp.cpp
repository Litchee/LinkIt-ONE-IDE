#include <Arduino.h>
#include "LGPRSUdp.h"
#include "LGPRS.h"
#include "vmtcp.h"

VMINT LGPRSUDP::getAPN() const
{
	return VM_TCP_APN_CMNET;
}

int LGPRSUDP::beginPacket(const char *host, uint16_t port)
{
	// DNS loopup and bypass to IP version
	int ret = LGPRS.hostByName(host, m_sendToIP);
	if(ret)
	{
		return beginPacket(m_sendToIP, port);	
	}
	else
	{
		return 0;
	}
}

