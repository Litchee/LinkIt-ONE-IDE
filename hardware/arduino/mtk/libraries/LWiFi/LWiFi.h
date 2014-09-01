#ifndef LWiFi_h
#define LWiFi_h

#include "Arduino.h"
#include "IPAddress.h"
#include "vmnwsetting.h"
#include "vmconn.h"
#include "WString.h"

class LWiFiConnectContext;

enum LWiFiEncryption
{
  LWIFI_OPEN, // Open networks
  LWIFI_WEP,  // WEP encrypted networks
  LWIFI_WPA,  // WPA1 and WPA2 networks
};

enum LWifiStatus
{
  LWIFI_STATUS_DISABLED,          // the LWiFi module is not enabled. use LWiFi.begin() to enable it.
  LWIFI_STATUS_DISCONNECTED,      // the LWiFi module is not connect to any AP, or the connection is lost due to bad signal strength
  LWIFI_STATUS_CONNECTED,         // the LWiFi module is connected to an AP
};

//LWiFiLoginInfo Class
class LWiFiLoginInfo
{
public:
  LWiFiEncryption m_enc;
  String m_password;
  String m_username;

public:
  LWiFiLoginInfo();
  LWiFiLoginInfo(LWiFiEncryption enc, const String &password);
  LWiFiLoginInfo(LWiFiEncryption enc, const String &password, const String &username);
};

//LWifi Class
class LWiFiClass
{
public:


  LWiFiClass();

  // DESCRIPTION
  //  turn on and initializes the WiFi module
  //
  // PARAMETERS
  //  N/A
  void begin();

  // DESCRIPTION
  //  uninitialize and turn off the WiFi module
  //
  // PARAMETERS
  //  N/A
  void end();

  // DESCRIPTION
  //  Start Wifi connection for OPEN networks
  //
  // PARAMETERS
  //  ssid: Pointer to the SSID string.
  int connect(const char* ssid);

  // DESCRIPTION
  //  Start Wifi connection to networks
  //  The login information are stored in loginInfo.
  //
  // PARAMETERS
  //  ssid: Pointer to the SSID string.
  //  loginInfo: an LWiFiKey that stores login information
  int connect(const char* ssid, const LWiFiLoginInfo &loginInfo);

  // DESCRIPTION
  //  Start Wifi connection with WEP encryption.
  //  Configure a key into the device. The key type (WEP-40, WEP-104)
  //  is determined by the size of the key (5 bytes for WEP-40, 13 bytes for WEP-104).
  //
  // PARAMETERS
  //  ssid: Pointer to the SSID string.
  //  key_idx: The key index to set. Valid values are 0-3.
  //  key: Key input buffer.
  int connectWEP(const char* ssid, const char* key);

  // DESCRIPTION
  //  Start Wifi connection with WPA/WPA-2 passphrase
  //
  // PARAMETERS
  //  ssid: Pointer to the SSID string.
  //  passphrase: Passphrase. Valid characters in a passphrase
  //              must be between ASCII 32-126 (decimal).
  int connectWPA(const char* ssid, const char *passphrase);

  // DESCRIPTION
  //  Disconnect from the WiFi AP
  //
  // RETURNS
  //  currently it always returns 0
  int disconnect(void);

  // DESCRIPTION
  //  Get the interface MAC address.
  //
  // RETURNS
  //  pointer to uint8_t array with length VM_WLAN_LOC_MAC_ADDR_LEN
  uint8_t* macAddress(uint8_t* mac);

  // DESCRIPTION
  //  Get the interface IP address.
  //
  // RETURNS
  //  Ip address value
  IPAddress localIP();

  // DESCRIPTION
  //  Get the interface subnet mask address.
  //
  // RETURNS
  //  subnet mask address value
  IPAddress subnetMask();

  // DESCRIPTION
  //  Get the gateway ip address.
  //
  // RETURNS
  //  gateway ip address value
  IPAddress gatewayIP();

  // DESCRIPTION
  //  Return the current SSID associated with the network
  //
  // RETURNS
  //  ssid string
  char* SSID();

  // DESCRIPTION
  //  Return the current BSSID associated with the network.
  //  It is the MAC address of the Access Point
  //
  // RETURNS
  //  pointer to uint8_t array with length WL_MAC_ADDR_LENGTH
  uint8_t* BSSID(uint8_t* bssid);

  // DESCRIPTION
  //  Return the current RSSI /Received Signal Strength in dBm)
  //  associated with the network
  //
  // RETURNS
  //  signed value
  int32_t RSSI();

  // DESCRIPTION
  //  Start scan WiFi networks available
  //
  // RETURNS
  //  Number of discovered networks
  int8_t scanNetworks();

  // DESCRIPTION
  //  Return the SSID discovered during the network scan.
  //
  // PARAMETERS
  //  networkItem: specify from which network item want to get the information
  //
  // RETURNS
  //  ssid string of the specified item on the networks scanned list
  char*	SSID(uint8_t networkItem);

  // DESCRIPTION
  //  Return the RSSI of the networks discovered during the scanNetworks
  //
  // PARAMETERS
  //  networkItem: specify from which network item want to get the information
  //
  // RETURNS
  //  signed value of RSSI of the specified item on the networks scanned list
  int32_t RSSI(uint8_t networkItem);

  // DESCRIPTION
  //  Return Connection status.
  //
  // RETURNS
  //  one of the value defined in LWifiStatus.
  //  It can be
  //    LWIFI_STATUS_DISABLED: the LWiFi module is not enabled. use LWiFi.begin() to enable it.
  //    LWIFI_STATUS_DISCONNECTED: the LWiFi module is not connect to any AP, or the connection is lost due to bad signal strength
  //    LWIFI_STATUS_CONNECTED: the LWiFi module is connected to an AP
  LWifiStatus status();

  // DESCRIPTION
  //  Resolve the given hostname to an IP address.
  //
  // PARAMETERS
  //  param aHostname: Name to be resolved
  //  param aResult: IPAddress structure to store the returned IP address
  //
  // RETURNS
  //  1 if aIPAddrString was successfully converted to an IP address,
  //  else error code
  int hostByName(const char* aHostname, IPAddress& aResult);


  friend class LWiFiClient;
  friend class LWiFiServer;

public:
  // TODO: should we use compilation firewall here?
  char m_macAddress[VM_WLAN_LOC_MAC_ADDR_LEN];
  vm_wlan_ip_info_struct m_ipInfo;  // IP info after being connected
  vm_wlan_conned_ap_info_struct m_apInfo;  // This stores BSSID and RSSI of connectd AP
  vm_wlan_cfg_ap_struct m_apParam;  // This stores SSID for connected AP
  vm_wlan_scan_result_struct m_scanInfo;  // Info of scanned APs
  VMINT m_lastError;

private:
  int wifiConnectImpl(LWiFiConnectContext &context);
};

extern LWiFiClass LWiFi;

#endif // #ifndef LWiFi_h
