/*
 * Button control brightness
 *
 * One button will increase the brightness while the other reduce the brightness
 * LED connect to D3
 *
 */

const int pwmPin    = 3;                            // use Digital pin D9
const int btnUp     = 5;                            // button up
const int btnDown   = 6;                            // button down

int cycle           = 1600;                         // Divide output into 9+1 = 10 portions
int sourceClock     = PWM_SOURCE_CLOCK_13MHZ;
int divider         = PWM_CLOCK_DIV8;               // The PWM frequency will be 13MHz / 8 / 10 = 162.5KHz


int offset          = 1;
int brightness      = 0;

// duty: 0-100
void setPwm(unsigned char duty)
{
    int __duty = map(duty, 0, 100, 0, 1600);
    analogWriteAdvance(pwmPin, sourceClock, divider, cycle, __duty);
}

// get button state: 
// 1: pressed
// 0: released
bool getButton(int pin)
{
    return (1-digitalRead(pin));
}

void setup()
{
    pinMode(pwmPin, OUTPUT);
    pinMode(btnUp, INPUT);
    pinMode(btnDown, INPUT);
}


void loop()
{
    if(getButton(btnUp))
    {
        if(brightness<100)brightness++;
        setPwm(brightness);
        delay(50);
    }
    
    if(getButton(btnDown))
    {
        if(brightness>0)brightness--;
        setPwm(brightness);
        delay(50);
    }
}