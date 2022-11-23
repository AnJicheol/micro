#include <avr/io.h>

int main(){
	
	volatile unsigned long int i, j;
	
	DDRC = 0xFF;
	DDRG |= 0x0F;
	
	PORTC = 0xFF;
	PORTG = 0x01;
	
	do{
	
		for(i = 0; i <= 200000; ++i)++j;
			
		PORTG = PORTG << 1;
		if(PORTG == 0x10) PORTG = 0x01;
	}
	while(1);
}
