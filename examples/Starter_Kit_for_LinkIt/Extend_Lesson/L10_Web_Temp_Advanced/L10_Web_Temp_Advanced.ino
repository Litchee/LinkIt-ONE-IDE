/*
 * Web Server & temperature
 * 
 * Note: 
 * 1.change the WIFI_AP to your ssid of Wi-Fi
 * 2.change WIFI_PASSWORD to key of your Wi-Fi
 * 3.as well as the WIFI_AUTH
 * 
 * When the code is finish uploading, open the serial monitor 
 * as soon as possible, then you can find that: "Please open your browser, and input the following address:"
 * and there will be an address below, such 192.168.1.100, copy it to your browser, press Enter, 
 * then you can see the temperature.
 */
#include <LTask.h>
#include <LWiFi.h>
#include <LWiFiServer.h>
#include <LWiFiClient.h>

#define WIFI_AP "LinkIt_ONE"
#define WIFI_PASSWORD "depot0510"
#define WIFI_AUTH LWIFI_WPA                 // choose from LWIFI_OPEN, LWIFI_WPA, or LWIFI_WEP according to your WiFi AP configuration


LWiFiServer server(80);


float tp[10];



float getTemperature()
{

    static float tmp = 0.01;
    tmp += 0.01;
    return (20+tmp);
}

void getNewTemperature()
{
    float tp_new = getTemperature();
    
    for(int i=9; i>=1; i--)
    {
        tp[i] = tp[i-1];
    }
    
    tp[0] = tp_new;
}

void setup()
{
    LTask.begin();
    LWiFi.begin();
    Serial.begin(9600);
    
    for(int i=0; i<10; i++)
    {
        tp[i] = getTemperature();
    }

    // keep retrying until connected to AP
    Serial.println("Connecting to AP");
    while (0 == LWiFi.connect(WIFI_AP, LWiFiLoginInfo(WIFI_AUTH, WIFI_PASSWORD)))
    {
        delay(1000);
    }

    printWifiStatus();

    Serial.println("Start Server");
    server.begin();
    Serial.println("Server Started");
}

int loopCount = 0;

void loop()
{
    // put your main code here, to run repeatedly:
    delay(500);
    loopCount++;
    LWiFiClient client = server.available();
        
    getNewTemperature();
    
    if (client)
    {
        Serial.println("new client");
        // an http request ends with a blank line
        boolean currentLineIsBlank = true;
        
        unsigned long timer_out = millis();
        
        while (client.connected())
        {
        
            if(millis()-timer_out > 5000)break;
            
            if (client.available())
            {
                // we basically ignores client request, but wait for HTTP request end
                int c = client.read();
                Serial.print((char)c);

                if (c == '\n' && currentLineIsBlank)
                {
                    Serial.println("send response");
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");  // the connection will be closed after completion of the response
                    client.println("Refresh: 5");  // refresh the page automatically every 5 sec
                    client.println();
                    client.println("<!DOCTYPE HTML>");
                    client.println("<html>");
                    // output the value of each analog input pin
                    
                    
                    for(int i=0; i<10; i++)
                    {
                        client.println(tp[i]);
                        client.println("<br />");
                    }
                    client.println("<br />");
                    client.println("</html>");
                    client.println();
                    break;
                }
                if (c == '\n')
                {
                    // you're starting a new line
                    currentLineIsBlank = true;
                }
                else if (c != '\r')
                {
                    // you've gotten a character on the current line
                    currentLineIsBlank = false;
                }
            }
        }
        // give the web browser time to receive the data
        delay(500);

        // close the connection:
        Serial.println("close connection");
        client.stop();
        Serial.println("client disconnected");
    }
}

void printWifiStatus()
{
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(LWiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = LWiFi.localIP();
    Serial.println("Please open your browser, and input the following address:");
    Serial.println(ip);

    Serial.print("\r\nsubnet mask: ");
    Serial.println(LWiFi.subnetMask());

    Serial.print("gateway IP: ");
    Serial.println(LWiFi.gatewayIP());

    // print the received signal strength:
    long rssi = LWiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}