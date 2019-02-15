#include<reg51.h>

delay(unsigned char);


       //PORT 2
sbit L_MOTORFORWARD=P1^4;     
sbit L_MOTORBACKWARD=P1^5;

 
sbit R_MOTORFORWARD=P1^6;
sbit R_MOTORBACKWARD=P1^7;   
 
sbit INT=P2^7;   
Motor_Init();
   
 
main()
{
Motor_Init();


  P1=0X0F;
  
while(1)
{ 


if(INT==1)
{
 if(P1==0x02)
 {
 L_MOTORFORWARD=1;     
 R_MOTORFORWARD=1;
 delay(250);         //FORWARD
 L_MOTORFORWARD=0;     
 R_MOTORFORWARD=0;
 
 
 }
 if(P1==0x04)
 {
 L_MOTORFORWARD=1;
 delay(250);
 L_MOTORFORWARD=0;    //RIGHT    
 L_MOTORBACKWARD=0;
 R_MOTORFORWARD=0;
 R_MOTORBACKWARD=0; 
 }
 if(P1==0x06)
 {
 R_MOTORFORWARD=1;
 delay(250);
  R_MOTORFORWARD=0;             //LEFT
  L_MOTORFORWARD=0;    
  L_MOTORBACKWARD=0;     
  R_MOTORBACKWARD=0;   

 }

 if(P1==0x08)
 {
 L_MOTORBACKWARD=1;
 R_MOTORBACKWARD=1;
 delay(250);        //BACK
 L_MOTORBACKWARD=0;
 R_MOTORBACKWARD=0;

 }

 }  //if
 } //while
}  //main

 delay(unsigned char time)
 {
 unsigned char i,j;
 for(i=0;i<time;i++)
 for(j=0;j<250;j++);
 } 


Motor_Init()
{
L_MOTORFORWARD=0;    
L_MOTORBACKWARD=0;


R_MOTORFORWARD=0;
R_MOTORBACKWARD=0;

delay(300);

L_MOTORFORWARD=1;    
L_MOTORBACKWARD=0;


R_MOTORFORWARD=1;
R_MOTORBACKWARD=0;
}  
   
   
     
