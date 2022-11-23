#include <avr/io.h>
#include <avr/interrupt.h>

int num[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x3F};
int u, t, h, th;


volatile unsigned long int i, j, counter;

void collision(int sum) {

	while(1){
		if(counter == 0) break;		

		th = counter/ 1000;
		h = (counter / 100) % 10 ;
		t = (counter /10) % 10;
		u = counter % 10;
	
		PORTG = 0x01;
		PORTC = num[u];
		for(j=0;j<=200; ++j);
		
		PORTG = 0x02;
		PORTC = num[t];
		for(j=0;j<=200;++j);

		PORTG = 0x04;
		PORTC = num[h];
		for ( j = 0; j <= 200; ++j);

		PORTG = 0x08;
		PORTC = num[th];
		for ( j = 0; j <= 200; ++j);
		counter --;
		
		for ( j = 0; j <= 1000; ++j);

	}


	for(int i = 0; i < 3; i++){
		
		for(j = 0; j <= 500000; j++);
		PORTB = 0xFF;
		for(j = 0; j <= 100000; j++);
		PORTB = 0x00; 
	
	}
	
}


int main() {


	DDRC = 0xFF;
	DDRG |= 0x0F; 

	
	DDRB = 0x10;
	
	EICRA = 0x00;
	EICRB = 0x08 + 0x02;
	EIMSK = 0x20 + 0x10;
	sei();

	counter = 2000;
	PORTG = 0x0F;

	do{
		th = counter/ 1000;
		h = (counter / 100) % 10 ;
		t = (counter /10) % 10;
		u = counter % 10;

		PORTG = 0x01;
		PORTC = num[u];
		for(j=0;j<=200; ++j);
		
		PORTG = 0x02;
		PORTC = num[t];
		for(j=0;j<=200;++j);

		PORTG = 0x04;
		PORTC = num[h];
		for ( j = 0; j <= 200; ++j);

		PORTG = 0x08;
		PORTC = num[th];
		for ( j = 0; j <= 200; ++j);
		
		}
		while(1);
		return 1;

}

ISR(INT4_vect){

	counter ++;
}

ISR(INT5_vect){

	collision(counter);
}

