/*
 * SMS Control Light
 * 
 * You should insert a SIM car and the GPRS antenna 
 * Send a "onxx" or "ONxx" to lighten the led for xx s
 * Send a "off" or "OFF" to make the led off
 *
 * LED connect to D3
 */

#include <LTask.h>
#include <LGSM.h>


const int pinLed = 3;               // led connect to D3

int onTime = 0;

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
            onTime = 0;
            
            for(int i=2; i<len; i++)
            {
                if((dtaget[i]>='0') && (dtaget[i]<='9'))
                {
                    onTime = 10*(i-2) + (dtaget[i]-'0');
                }
                else
                {
                    break;
                }
            }
        }
        else if((dtaget[0] == 'O' && dtaget[1] == 'F' && dtaget[2] == 'F') || (dtaget[0] == 'o' && dtaget[1] == 'f' && dtaget[2] == 'f'))
        {
            onTime = 0;
        }
    }
    
    if(onTime>0)
    {
        digitalWrite(pinLed, HIGH);
        onTime--;
    }
    else
    {
        digitalWrite(pinLed, LOW);
    }
    
    delay(1000);
}