#define F_CPU 1200000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_BIT_GREEN _BV(PB3)
#define LED_BIT_RED _BV(PB1)
#define SENSOR_BIT _BV(PB0)

#define FALSE (0)
#define TRUE !FALSE

// #include <avr/interrupt.h>

// volatile unsigned long millis;

// ISR(TIMER0_OVF_vect)
// {
//  millis++;
// }

typedef char bool;

void reaction(bool tone)
{

    if(tone)
    {
        PORTB |= LED_BIT_RED;
    }
    
    PORTB |= LED_BIT_GREEN;
    _delay_ms(300);

    if(tone)
    {
        PORTB &= ~LED_BIT_RED;
    }

    PORTB &= ~LED_BIT_GREEN;
    _delay_ms(300);

    if(tone)
    {
        PORTB |= LED_BIT_RED;
    }

    PORTB |= LED_BIT_GREEN;
    _delay_ms(300);

    if(tone)
    {
        PORTB &= ~LED_BIT_RED;
    }

    PORTB &= ~LED_BIT_GREEN;
    _delay_ms(300);

    if(tone)
    {
        PORTB |= LED_BIT_RED;
    }

    PORTB |= LED_BIT_GREEN;
    _delay_ms(300);

    if(tone)
    {
        PORTB &= ~LED_BIT_RED;
    }

    PORTB &= ~LED_BIT_GREEN;
    _delay_ms(300);
}

bool check_sensor(void)
{
    uint8_t i = 0x00;
    i = PINB;

    return !((1 << PB0) & i);
}

int main(void)
{

    // TIMSK =(1<<TOIE0);  // timer0 enable
    // TCCR0 = (1<<CS01) | (1<<CS00); // prescaler 1/64

    // volatile unsigned  long curTime, lastTime, period;

    // millis=0;
    // lastTime=0;
    // period=1000; // 1 sec
 //    sei();

    DDRB|=LED_BIT_GREEN;
    DDRB|=LED_BIT_RED;

    DDRB &= ~SENSOR_BIT;
    PORTB |= SENSOR_BIT;

    

    bool flag_on = TRUE;

    while(1){

        if(!check_sensor())
        {
            PORTB &= ~LED_BIT_GREEN;
            PORTB &= ~LED_BIT_RED;

            if(flag_on)
            {
                PORTB |= LED_BIT_GREEN;
                _delay_ms(1000);

                if(check_sensor())
                {

                }
                else
                {
                    reaction(FALSE);
                    reaction(FALSE);

                    if(!check_sensor())
                        flag_on = FALSE;
                }


                
            }
        }
        else
        {
            if (!flag_on)
            {
                _delay_ms(4000);
                if(check_sensor())
                {
                    reaction(TRUE);
                    flag_on = TRUE;
                }
            }
            else if(flag_on)
            {
                reaction(FALSE);
            }
            
            
/*
            PORTB |= LED_BIT_RED;
            PORTB |= LED_BIT_GREEN;
            _delay_ms(300);
            PORTB &= ~LED_BIT_GREEN;
            _delay_ms(300);
            PORTB |= LED_BIT_GREEN;
            _delay_ms(300);
                        PORTB &= ~LED_BIT_GREEN;
                        _delay_ms(300);
                        PORTB |= LED_BIT_GREEN;
            _delay_ms(300);
            PORTB &= ~LED_BIT_GREEN;
            _delay_ms(300);
*/
                        //PORTB &= ~LED_BIT_GREEN;
                        //PORTB &= LED_BIT_RED;
        }

        //PORTB |= LED_BIT_GREEN;
        //_delay_ms(500);
        //PORTB |= LED_BIT_RED;
        //_delay_ms(500);
        //PORTB &= ~LED_BIT_GREEN;
        //_delay_ms(500);
        //PORTB &= ~LED_BIT_RED;
        //_delay_ms(500);
    }
}
