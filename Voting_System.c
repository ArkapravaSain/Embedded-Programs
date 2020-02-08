#include<mega16.h>
#include<delay.h>
#include<mylcd2.h>

void main()
{
int a=0,b=0,c=0,d=0,i=0; //For storing variables
int w=0,x=0,y=0,z=0;
PORTC=0b01111111;  //Switch Pins
DDRC=0b00000000;

PORTD=0b00000000;  //LEDs and Buzzer
DDRD=0b00000111;
lcd_init();

while(1)
{ 
 while(PINC.0==0 || i==0)
  {
   x=0;
   y=0;
   z=0;
   w=0;
   PORTD.1=0;
   PORTD.0=1; 
   lcd_s("EVERY VOTE IS");
   lcd_xy(1,5);
   lcd_s("PRECIOUS");
   delay_ms(2000);
   lcd_cmd(0X01);
   lcd_s("GREENFIELD VOTE");
   lcd_xy(1,0);
   lcd_s("SESSION 2011-12");
   delay_ms(2000);
   lcd_cmd(0X01);
   lcd_s("SUPRT UR TEAM");
   lcd_xy(1,0);
   lcd_s("FIND SIGN & VOTE");
   delay_ms(2000);
   lcd_cmd(0X01);
   lcd_s("SW1:TM1 SW2:TM2");
   lcd_xy(1,0);
   lcd_s("SW3:TM3 SW4:TM4");
   i=1;
   }

    while(PINC.2==0 && w==0 && x==0 && y==0 && z==0 && i==1)
   {
    w=1;
    i=0;
    a++;
    PORTD.2=1;
    delay_ms(1000);
    PORTD.2=0;
    lcd_cmd(0X01);
    lcd_s("THNKS FOR VOTE");
    delay_ms(1000);
    lcd_cmd(0X01);
   }
   
   while(PINC.3==0 && w==0 && x==0 && y==0 && z==0 && i==1)
   {
    x=1;
    i=0;
    PORTD.2=1;
    delay_ms(1000);
    PORTD.2=0;
    lcd_cmd(0X01);
    lcd_s("THNKS FOR VOTE"); 
    delay_ms(1000);
    lcd_cmd(0X01);
    
   }
   while(PINC.4==0 && w==0 && x==0 && y==0 && z==0 && i==1)
   {
    y=1;
    i=0;
    c++;
    PORTD.2=1;
    delay_ms(1000);
    PORTD.2=0;
    lcd_cmd(0X01);
    lcd_s("THNKS FOR VOTE");
     delay_ms(1000);
    lcd_cmd(0X01);
   }
   while(PINC.5==0 && w==0 && x==0 && y==0 && z==0 && i==1)
   {
    z=1; 
    i=0;
    d++;
    PORTD.2=1;
    delay_ms(1000);
    PORTD.2=0;
    lcd_cmd(0X01);
    lcd_s("THNKS FOR VOTE");
     delay_ms(1000);
    lcd_cmd(0X01); 
   }
   
   
  while(PINC.6==0) //RESULT
  {
   lcd_cmd(0X01);
   lcd_s("TEAMA=");
   lcd_1d(a);
   lcd_s(" TEAMB=");
   lcd_1d(b);
   lcd_xy(1,0);
   lcd_s("TEAMC=");
   lcd_1d(c);
   lcd_s(" TEAMD=");
   lcd_1d(d);
   }
   
   
   while(PINC.1==0)  //STOP
   {
   PORTD.0=0;
   PORTD.1=1;
   lcd_cmd(0X01);
   lcd_s("GOING OFF");
   delay_ms(3000);
   lcd_cmd(0X01);
   } 
   
   
    
  

}
}