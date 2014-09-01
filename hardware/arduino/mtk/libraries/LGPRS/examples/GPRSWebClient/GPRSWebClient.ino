#include <LGPRS.h>
#include <LGPRSClient.h>
#include <LGPRSServer.h>

char server[] = "arduino.cc";
char path[] = "/asciilogo.txt";
int port = 80; // HTTP

LGPRSClient client;

void setup()
{
  // setup Serial po
  Serial.begin(115200);

  Serial.println("Attach to GPRS network by auto-detect APN setting");
  while (!LGPRS.attachGPRS())
  {
    delay(500);
  }

  // if you get a connection, report back via serial:
  Serial.print("Connect to ");
  Serial.println(server);
  if (client.connect(server, port))
  {
    Serial.println("connected");
    // Make a HTTP request:
    client.print("GET ");
    client.print(path);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
  }
  else
  {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}

void loop()
{
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client.available())
  {
    char c = client.read();
    Serial.print(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.available() && !client.connected())
  {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    for (;;)
      ;
  }
}
