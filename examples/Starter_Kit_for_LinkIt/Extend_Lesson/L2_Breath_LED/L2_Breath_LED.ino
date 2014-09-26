/*
 * Breath LED
 *
 * LED connect to D9
 *
 */

const int pwmPin = 9;                           // use Digital pin D9
 
int cycle        = 1600;                        // Divide output into 9+1 = 10 portions
int sourceClock  = PWM_SOURCE_CLOCK_13MHZ;
int divider      = PWM_CLOCK_DIV8;              // The PWM frequency will be 13MHz / 8 / 10 = 162.5KHz


int offset       = 1;
int brightness   = 0;

// duty: 0-100
void setPwm(unsigned char duty)
{
    int __duty = map(duty, 0, 100, 0, 1600);
    analogWriteAdvance(pwmPin, sourceClock, divider, cycle, __duty);
}


void setup()
{
    pinMode(pwmPin, OUTPUT);
}

void loop()
{
    for(int i=0; i<100; i++)
    {
        setPwm(i);
        delay(10);
    }
    
    delay(200);
    
    for(int i=99; i>=0; i--)
    {
        setPwm(i);
        delay(10);  
    }
    
    delay(500);

}