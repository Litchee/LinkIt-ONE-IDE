#include <LTask.h>
#include <LWiFi.h>

void setup()
{
  LTask.begin();
  Serial.begin(115200);
}

// scan WiFi AP every 5 secs
void loop()
{
  // turn on wifi
  LWiFi.begin();
  Serial.println("scan start");
  int apNum = LWiFi.scanNetworks();
  Serial.println("scan end");
  Serial.println(apNum);
  for (int i = 0; i < apNum; ++i)
  {
    Serial.print("AP ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(LWiFi.SSID(i));
    Serial.print(" dB=");
    Serial.println(LWiFi.RSSI(i));
  }

  // turn off wifi
  LWiFi.end();
  Serial.println("Finish");
  delay(5000);
}


