#include<mega16.h>
#include<delay.h>
void main()
{
int counter=0,p=0,q=0;
PORTA=0b00000000; // Motor 
DDRA=0b00010001;
PORTB=0b00000000;   //LEDs
DDRB=0b00000011;
PORTC=0b00000111;   //Switches
DDRC=0b00000000;

while(1)
{      
while(PINC.0==0 && counter<5)
{
delay_ms(400);
counter++;
}
    
while(p<=counter && PINC.2==0)
{
PORTA.0=1;
PORTA.4=0;
PORTB.0=1;
delay_ms(1000);
PORTB.0=0;
delay_ms(1000);
p=p+1;
if(p>counter)
{
PORTB.1=1;
PORTA.0=0;
PORTA.4=0;
}}

while(PINC.1==0 && counter>0)
{
delay_ms(400);
counter--;
}
    
while(q<=counter && PINC.2==0)
{
PORTA.0=0;
PORTA.4=1;
PORTB.0=1;
delay_ms(1000);
PORTB.0=0;
delay_ms(1000);
q=q+1;
if(q<counter)
{
PORTB.1=1;
PORTA.0=0;
PORTA.4=0;
}}
  


}
}
