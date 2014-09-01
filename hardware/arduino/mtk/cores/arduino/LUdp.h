#ifndef ludp_h
#define ludp_h

#include <Udp.h>
#include <vector>

#define UDP_TX_PACKET_MAX_SIZE 24

class LUDP : public UDP {
protected:
  uint16_t m_port; // local port to listen on
  VMINT m_serverHandle;

  IPAddress m_sendToIP; // remote IP address for outgoing packet whilst it's being processed
  uint16_t m_sendToPort; // remote port for the outgoing packet whilst it's being processed
  std::vector<VMUINT8> m_writeBuffer;
  VMINT m_writePos;

  IPAddress m_recvIP; // remote IP address for outgoing packet whilst it's being processed
  uint16_t m_recvPort; // remote port for the outgoing packet whilst it's being processed
  std::vector<VMUINT8> m_recvBuffer;
  VMINT m_recvPos;

  static const VMINT INIT_WRITE_BUFFER_SIZE = 32;
  static const VMINT INIT_RECV_BUFFER_SIZE = 1024;  // typical MTU of web is 512 bytes, 1KB buffer should be sufficient

  static boolean udpBegin(void* userdata);
  static boolean udpStop(void* userdata);
  static boolean udpSend(void* userdata);
  static boolean udpRecv(void* userdata);
  static void udpCallback(VMINT hdl, VMINT event);

protected:
  // child class shoudl return proper APN enum
  virtual VMINT getAPN() const = 0;

public:
  LUDP();  // Constructor
  virtual uint8_t begin(uint16_t);	// initialize, start listening on specified port. Returns 1 if successful, 0 if there are no sockets available to use
  virtual void stop();  // Finish with the UDP socket

  // Sending UDP packets
  
  // Start building up a packet to send to the remote host specific in ip and port
  // Returns 1 if successful, 0 if there was a problem with the supplied IP address or port
  virtual int beginPacket(IPAddress ip, uint16_t port);

  // different DNS lookup should be defined by child classes
  virtual int beginPacket(const char *host, uint16_t port) = 0;

  // Finish off this packet and send it
  // Returns 1 if the packet was sent successfully, 0 if there was an error
  virtual int endPacket();
  // Write a single byte into the packet
  virtual size_t write(uint8_t);
  // Write size bytes from buffer into the packet
  virtual size_t write(const uint8_t *buffer, size_t size);
  
  using Print::write;

  // Start processing the next available incoming packet
  // Returns the size of the packet in bytes, or 0 if no packets are available
  virtual int parsePacket();
  // Number of bytes remaining in the current packet
  virtual int available();
  // Read a single byte from the current packet
  virtual int read();
  // Read up to len bytes from the current packet and place them into buffer
  // Returns the number of bytes read, or 0 if none are available
  virtual int read(unsigned char* buffer, size_t len);
  // Read up to len characters from the current packet and place them into buffer
  // Returns the number of characters read, or 0 if none are available
  virtual int read(char* buffer, size_t len) { return read((unsigned char*)buffer, len); };
  // Return the next byte from the current packet without moving on to the next byte
  virtual int peek();
  virtual void flush();	// Finish reading the current packet

  // Return the IP address of the host who sent the current incoming packet
  virtual IPAddress remoteIP() { return m_recvIP; };
  // Return the port of the host who sent the current incoming packet
  virtual uint16_t remotePort() { return m_recvPort; };
};

#endif
