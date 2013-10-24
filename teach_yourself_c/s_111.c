#include <stdio.h>
#include <conio.h>

int main (void)

{
   short i;
   unsigned short u;
   
   u=33000;
   i=u;
   
   printf ("%hd  %hu",i,u);
   
   getch();
}
