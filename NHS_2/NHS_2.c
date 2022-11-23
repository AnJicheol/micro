#include <avr/io.h>

int main (){
	
	unsigned char i;
	unsigned char portData;

	volatile unsigned long int j;
	volatile unsigned long int dummyVar;

	DDRA = 0xFF;


	while(1){

		j = 0;
		dummyVar = 0;
		portData = 0x80;
		
		for(i = 0; i< 8; i++){
		
			PORTA = portData;
	
			for(j = 0; j <= 20000; j++) dummyVar ++;

			portData = portData >> 1;

		}
	}

	return (1);

}
