#include <avr/io.h>

#include <avr/interrupt.h>

#define OVERFLOW 65536

#define TICKS_PER_SEC 1000

volatile unsigned long int i=0;

unsigned int tick_time=0;

 

int number[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};

 

unsigned int tick_time;

ISR(TIMER0_OVF_vect)

{

	TCNT0=OVERFLOW-125;

	tick_time++;

	if(tick_time==TICKS_PER_SEC) {

		 i++;

	tick_time=0;

	}

}

int main()

{

	DDRC=0xFF;

	DDRG=0x0F;

	TCNT0=OVERFLOW - 125;

	TIMSK = 0x01;

	sei();

	TCCR0 = 0x05;

	for(;;) {

			

			PORTC=number[i%60%10];

			PORTG=0x01;

 

			PORTC=number[i%60/10];

			PORTG=0X02;

 

			PORTC=number[i/60%10];

			PORTG=0x04;

 

			PORTC=number[i/60/10];

			PORTG=0x08;

			}

while(1);

return(1);

}
