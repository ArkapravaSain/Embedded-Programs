#include<mega16.h>
#include<delay.h>
void main()
{
int up=0,down=0,floor=0;
PORTA=0b00000000; // Motor 
DDRA=0b00010001;
PORTB=0b00000000;   //LEDs
DDRB=0b00000011;
PORTC=0b00000111;   //Switches
DDRC=0b00000000;

while(1)
{

 if(PINC.0==0) //Increment in floor
  {
   delay_ms(300);
   up++;
   floor++;
   }


 if(PINC.1==0)   //Decrement in Floor
 {
   delay_ms(300);
   down++;
   floor--;
 }

 
 
 if(PINC.2==0)
 { 
  PORTB.1=0;
  while(up!=0)
  {
   PORTA.0=1;//Rotate ClockWise
   PORTA.4=0;
   PORTB.0=1;
   delay_ms(1000);
   PORTB.0=0;
   delay_ms(1000);
   up--;
   floor++;
   }
   PORTB.1=1; //Red Light ON
   PORTA.0=0;//stop Motor
   PORTA.4=0;
    
  }  
  
  
 if(PINC.2==0)
 {   
  PORTB.1=0;     //Turn off red Light
  while(down!=0 && floor>=0)
  {
   PORTA.0=0;//Rotate Anti-ClockWise
   PORTA.4=1;
   PORTB.0=1;        //Blink green Light
   delay_ms(1000);
   PORTB.0=0;
   delay_ms(1000);
   down--;
   }
   PORTB.1=1; //Red Light on
   PORTA.0=0;//stop Motor
   PORTA.4=0; 
  }

}
}
