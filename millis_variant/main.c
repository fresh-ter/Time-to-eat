/* timer.c LED Blink whitout delay via 8-bit Timer0 for AVR ATmega8 */
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "millis.h"




#define LED_BIT_RED _BV(PB1)
#define LED_BIT_GREEN _BV(PB3)


int main(void)
{
    init();
    //init_millis();
    unsigned long timer_green, timer_red;
    timer_red=timer_green=0;

    DDRB|=LED_BIT_RED;
    DDRB|=LED_BIT_GREEN;
    PORTB ^= LED_BIT_RED;
    PORTB ^= LED_BIT_GREEN;

    // _delay_ms(1000);

    // PORTB ^= LED_BIT_RED;

    // _delay_ms(1000);

    // asm("rjmp 0x0000");

        

 //    for (;;)
    // {
    //  if (millis() - timer_green > 500)
    //  {
    //      PORTB ^= LED_BIT_GREEN;
    //      timer_green=millis();
    //  }

    //  if (millis() - timer_red > 1000)
    //  {
    //      PORTB ^= LED_BIT_RED;
    //      timer_red=millis();
    //  }
        
    // }

        return 0;
}
