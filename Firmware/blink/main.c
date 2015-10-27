#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

void led_on(uint8_t led_num);
void led_off(uint8_t led_num);

int main(void)
{
    DDRC |= _BV(DDC0) | _BV(DDC1) | _BV(DDC2) | _BV(DDC3); 
    
    while(1) 
    {
        led_on(1);
        led_off(3);
        _delay_ms(100);
        led_on(2);
        led_off(4);
        _delay_ms(100);
        led_on(3);
        led_off(1);
        _delay_ms(100);
        led_on(4);
        led_off(2);
        _delay_ms(100);
    }
}

void led_on(uint8_t led_num)
{
    switch(led_num)
    {
        case 1:
            PORTC |= _BV(PC0);
            break;
        case 2:
            PORTC |= _BV(PC1);
            break;
        case 3:
            PORTC |= _BV(PC2);
            break;
        case 4:
            PORTC |= _BV(PC3);
            break;
    }
}

void led_off(uint8_t led_num)
{
    switch(led_num)
    {
        case 1:
            PORTC &= ~(_BV(PC0));
            break;
        case 2:
            PORTC &= ~(_BV(PC1));
            break;
        case 3:
            PORTC &= ~(_BV(PC2));
            break;
        case 4:
            PORTC &= ~(_BV(PC3));
            break;
    }
}
