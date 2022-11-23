#include <avr/io.h>

int main(){
	
	volatile unsigned long int i, j;
	unsigned char PortInitValue = 0x01;

	DDRA = 0xFF;
	PORTA = PortInitValue;

	do{

		for(i = 0; i <= 200000; ++i){
			++j;
		}
			
		
		if((PortInitValue & 0x80) == 0x80){

			PortInitValue = 0x01;
		}
		
		else{
			PortInitValue = PortInitValue << 1;
		}

				
		PORTA = PortInitValue;
	}
	while(1);
}
