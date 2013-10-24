#include <stdio.h>
#include <conio.h>

int main (void){
   char *p,**m,str[40];
   
 //  gets (str);
   p=str;
   m=&p;
 
 gets (*m);
 printf ("%s",*m);
 
 
 //printf (p);
 //printf(m); //WHAT HAPPENS WITH M**
   
   getch();
}
