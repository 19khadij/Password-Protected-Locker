/*
 * TRY1.c
 *
 * Created: 7/27/2022 8:16:29 PM
 * Author : CSC
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <string.h>


int main(void)

{
	DDRA=0x01;
	
	DDRB|=1<<PB3;
	DDRB&=~(1<<PB2);
	
	DDRC=0xFF;
	int j;
	
	//DDRC=0x00;//
	//DDRB=(1<<PINB1);//
	UBRR1H=0x00;
	UBRR1L=0x05;
	
	UCSR1B =(1<<RXEN1);
	UCSR1C =(1<<USBS1)|(3<<UCSZ10);
	unsigned char receiveData;
	int index;
	char Original_Password='4';
	
	char push_button;
	
	/* Replace with your application code */
	while (1){
	
		PORTC=0;
		receiveData=0;
		while(!(UCSR1A&(1<<RXC1)));
		receiveData=UDR1;
		
		PORTC=receiveData;
		if (receiveData==Original_Password){
		//Rotate motor to 0'//
		PORTA=0x01;
		_delay_ms(10);
		PORTA=0x00;
		_delay_ms(10);
		
		//Rotate to 90//
		PORTA=0x01;
		_delay_ms(100);
		PORTA=0x00;
		_delay_ms(100);
		
		PORTB|=1<<PB2;
		UCSR1B =(1<<TXEN1);
		/*UCSR1B |=(1<<RXEN1);*/
		
		
		while(!(UCSR1A&(1<<UDRE1)));
		UDR1=0b00000001;
		/*PORTD=0b01000000;
		_delay_ms(1000);*/
	}
	else if(receiveData!=Original_Password){
		PORTB|=1<<PB2;
		UCSR1B =(1<<TXEN1);
		/*UCSR1B |=(1<<RXEN1);*/
		
		
		while(!(UCSR1A&(1<<UDRE1)));
		UDR1=0b00000010;
		PORTA=0x00;
		/*PORTD=0b11000110;
		_delay_ms(1000);*/
	};
	
	
	
	}
}





