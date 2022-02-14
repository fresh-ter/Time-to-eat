#include <avr/interrupt.h>
volatile unsigned long ovrf=0;
unsigned long x;
ISR(TIM0_OVF_vect){
    ovrf++; //Increment counter every 256 clock cycles
}
unsigned long millis(){
    
    asm("cli"); 
    /*Scale number of timer overflows to milliseconds*/
    #if F_CPU < 150000 && F_CPU > 80000
    x = ovrf * 2;
    #elif F_CPU == 600000
    x = ovrf / 2;
    #elif F_CPU == 1000000
    x = ovrf / 4;
    #elif F_CPU == 1200000
    x = ovrf / 5;
    #elif F_CPU == 4000000
    x = ovrf / 16;
    #elif F_CPU == 4800000
    x = ovrf / 19;
    #elif F_CPU == 8000000
    x = ovrf / 31;
    #elif F_CPU == 9600000
    x = ovrf / 37;
    #elif F_CPU == 10000000
    x = ovrf / 39;
    #elif F_CPU == 12000000
    x = ovrf / 47;
    #elif F_CPU == 16000000
    x = ovrf / 63;
    #else
    #error This CPU frequency is not defined
    #endif
    asm("sei");
    return x;
}

void init(){
    //Setup timer interrupt and PWM pins
    TCCR0B |= _BV(CS00);
    TCCR0A |= _BV(WGM00)|_BV(WGM01);
    TIMSK0 |= 2;
    TCNT0=0; 
    sei();
    ADMUX=0;
    //Set up ADC clock depending on F_CPU
    #if F_CPU <= 200000
    ADCSRA |= _BV(ADEN);
    #elif F_CPU <= 1200000 && F_CPU > 200000
    ADCSRA |= _BV(ADEN) | _BV(ADPS1);
    #elif F_CPU > 1200000 && F_CPU < 6400001
    ADCSRA |= _BV(ADEN) | _BV(ADPS2);
    #else
    ADCSRA |= _BV(ADEN) | _BV(ADPS1) | _BV(ADPS0) | _BV(ADPS2);
    #endif
}
