/*
 * try.c
 *
 * Created: 7/27/2022 7:49:35 PM
 * Author : CSC
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <string.h>


int GetKeyPressed(void);
int main(void)

{   
	int key;
	char digit[20]={'7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3','-', 'A', '0', '=','+','\0'};
	DDRB|=1<<PB3;
    DDRB&=~(1<<PB2);
	PORTB|=1<<PB2;
	

	DDRC=0x00;
	DDRD=0xF0;
	DDRB=(1<<PINB1);
	DDRA=0xFF;
	
	UBRR1H=0x00;
	UBRR1L=0x05;
	UCSR1B =(1<<TXEN1);
	/*UCSR1B |=(1<<RXEN1);*/
	UCSR1C =(1<<USBS1)|(3<<UCSZ10);
	
	
	int i=0;
	char password[4]={};
    
	int length_of_array;
	unsigned char receiveData;
    /* Replace with your application code */
    while (1) 
	
    {/*key = GetKeyPressed();
	    if(key!=16){
		    while(!(UCSR1A&(1<<UDRE1)));
		    UDR1=digit[key];*/
	 
		key = GetKeyPressed();
		if(key!=16){
			    while(!(UCSR1A&(1<<UDRE1)));
				UDR1=digit[key];
				
				i=i+1;
				/*password[i]+=digit[key];
				i=i+1;
				}*/
			
		}
		
		/* length_of_array=(int)( sizeof(password) / sizeof(password[0]) );
		 if(length_of_array==4){
				for (i = 1; i < 5;i++)
				{
				   while(!(UCSR1A&(1<<UDRE1)));
				   UDR1=password[i];
				
					
					
				  _delay_ms(1000);}
			      
		   }*/
		if (i==1){
		UCSR1B =(1<<RXEN1);
		
		PORTC=0;
		receiveData=0;
		while(!(UCSR1A&(1<<RXC1)));
		receiveData=UDR1;
		PORTC=receiveData;
		if(receiveData==0b00000001){
			PORTA=0b11000000;
			_delay_ms(1000); }
		else if(receiveData!=0b00000001){
			PORTA=0b11000110;
			_delay_ms(1000); }}
		
		
		
    }
}
int GetKeyPressed(void){
	char x;
	PORTB=0x00;
	int data;
	x=PINC;
	if(x==0x01)
	{
		data=(PIND&0x0F);
		
		return data;
	}
	return 16;
}




