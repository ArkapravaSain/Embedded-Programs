#include<mega16.h>
#include<delay.h>
int p[]={ 0X3F,0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
int i=0;
int j=0;
int a=0;
int b=0;
void main()
{

PORTB=0b00000111;
DDRB=0b00000000;
PORTC=0X00;
DDRC=0XFF;
PORTD=0X00;
DDRD=0XFF;
PORTC=p[0];
PORTD=p[0];
while(1)
{

while(PINB.0==0)
  {
   while(i<10)
   {
     while(j<10)
      { a=i;
        b=j;
        delay_ms(500);
        PORTD=p[j];
        PORTC=p[i];
        j++;
        while(PINB.1==0)
        {
        i=10;
        j=10;
        }
      }
    i++;
    j=0;     
   }
   
 
   }

  while(PINB.1==0)
  {
   delay_ms(300);
   PORTD=p[b];
   PORTC=p[a];
  } 
    
  
  while(PINB.2==0)  
  {
  delay_ms(300);
  i=0;
  j=0;
  PORTC=p[0];
  PORTD=p[0];
  }
  
  
  
  
  
  
       
        
} 
} 