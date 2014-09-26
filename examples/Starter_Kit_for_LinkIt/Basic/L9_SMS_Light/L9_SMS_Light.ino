/*
 * SMS Control Light
 * 
 * You should insert a SIM car and the GPRS antenna 
 * Send a "on" or "ON" to lighten the led
 * Send a "off" or "OFF" to make the led off
 *
 * LED connect to D3
 */

#include <LTask.h>
#include <LGSM.h>


const int pinLed = 3;               // led connect to D3

void setup()
{
    Serial.begin(9600);
    
    while(!LSMS.ready())
    {
        delay(1000);
    }
    
    Serial.println("GSM OK!!");
    
}


void loop()
{

    char p_num[20];
    int len = 0;
    char dtaget[500];

    if(LSMS.available()) // Check if there is new SMS
    {
    
        LSMS.remoteNumber(p_num, 20); // display Number part
        Serial.println("There is new message.");
        
        Serial.print("Number:");
        Serial.println(p_num);
        Serial.print("Content:"); // display Content part     

        while(true)
        {
            int v = LSMS.read();
            if(v < 0)
            break;

            dtaget[len++] = (char)v;
            Serial.print((char)v);
        }

        Serial.println();
        LSMS.flush(); // delete message

        
        if((dtaget[0] == 'O' && dtaget[1] == 'N') || (dtaget[0] == 'o' && dtaget[1] == 'n'))
        {
            digitalWrite(pinLed, HIGH);        // lamp on
        }

        else if((dtaget[0] == 'O' && dtaget[1] == 'F' && dtaget[2] == 'F') || (dtaget[0] == 'o' && dtaget[1] == 'f' && dtaget[2] == 'f'))
        {
            digitalWrite(pinLed, LOW);         // lamp off
        }
    }
}