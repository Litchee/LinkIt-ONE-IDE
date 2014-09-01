#ifndef lwifiudp_h
#define lwifiudp_h

#include <Udp.h>
#include <LUdp.h>

class LWiFiUDP : public LUDP
{
public:
  virtual int beginPacket(const char *host, uint16_t port);
  using LUDP::beginPacket;

protected:
  virtual VMINT getAPN() const;
};

#endif
