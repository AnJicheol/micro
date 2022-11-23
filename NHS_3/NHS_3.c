#include <avr/io.h>

int main (){
	
	unsigned char i;
	unsigned int R = 0x10;
	unsigned int L = 0x8;

	volatile unsigned long int j;
	volatile unsigned long int dummyVar;

	DDRA = 0xFF;
	PORTA = R + L;

	while(1){

		j = 0;
		dummyVar = 0;
	
		for(i = 0; i< 3; i++){
		
			for(j = 0; j <= 200000; j++) dummyVar ++;
			R = R << 1;
			L = L >> 1;

			PORTA = R + L;

		}

		for(i = 0; i< 3; i++){
		
			for(j = 0; j <= 200000; j++) dummyVar ++;

			R = R >> 1;
			L = L << 1;

			PORTA = R + L;

		}

	}

	return (1);

}
