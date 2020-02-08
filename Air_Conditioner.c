#include<mega16.h>
#include<delay.h>
#include<mylcd.h>

void main()
{
int i=25;
int j=0;
PORTC=0b00000000;  //Switch Pins
DDRC=0b00000000;

PORTD=0b00000000;  //Motor and LEDs
DDRD=0b00001111;

lcd_init();
PORTD.3=1;
while(1)
{ 
 while(PINC.0==1)
  { 
   PORTD.3=0;
   PORTD.2=1;
   lcd_s("VOLTAS AC");
   lcd_xy(1,0);
   lcd_s("VERSION V0.4");
   delay_ms(5000);
   lcd_cmd(0X01);
   lcd_xy(0,0);
   lcd_s("TEMP= 025");
   lcd_xy(0,9);
   lcd_char(0XDF);
   lcd_xy(0,10);
   lcd_s("C");  
   lcd_xy(1,0);
   lcd_s("S:NORMAL   |+|-|");
   PORTD.0=0;
   PORTD.1=1;
   j=1;
   
   } 
 
 while(PINC.1==1 && i<=40 && j==1)
 {
   i++;
   lcd_xy(0,6);
   lcd_3d(i);
   lcd_xy(1,2);
   if(i<=10)
   { 
   lcd_s("VERY COLD");
   } 
   if(i>10 && i<18)
   { 
   lcd_s("COLD     ");
   }
   if(i>=18 && i<27)
   { 
   lcd_s("NORMAL   ");
   }
   if(i>=27 && i<35)
   { 
   lcd_s("HOT      ");
   }
   if(i>=36)
   { 
   lcd_s("VERY HOT ");
   }
   lcd_xy(1,11);
   lcd_s("  ");
   delay_ms(200);
   lcd_xy(1,11);
   lcd_s("+1"); 
 
 }
  //Tempertature Decrease 
  
  while(PINC.2==1 && i>5 && j==1)
 {
   i--;
   lcd_xy(0,6);
   lcd_3d(i);
   lcd_xy(1,2);
   if(i<=10)
   { 
   lcd_s("VERY COLD");
   } 
   if(i>10 && i<18)
   { 
   lcd_s("COLD     ");
   }
   if(i>=18 && i<27)
   { 
   lcd_s("NORMAL   ");
   }
   if(i>=27 && i<35)
   { 
   lcd_s("HOT      ");
   }
   if(i>=36)
   { 
   lcd_s("VERY HOT ");
   }
   lcd_xy(1,13);
   lcd_s("  ");
   delay_ms(150);
   lcd_xy(1,13);
   lcd_s("-1"); 
 
 }
 
 //STOP AC
 while(PINC.3==1 && j==1)
 {
   lcd_cmd(0X01);
   lcd_xy(0,0);
   lcd_s("AC GOING OFF");
   delay_ms(3000);
   lcd_cmd(0X01);
   PORTD.0=0;
   PORTD.1=0;
   PORTD.2=0;
   PORTD.3=1;
 }
   
    
   
   
    
  

}
}