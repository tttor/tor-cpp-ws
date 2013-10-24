#include <stdio.h>
#include <conio.h>

int main(void)
{
   char user,ch;
   
   do
   { 
      printf ("enter : ");
      ch=getch();
      
      printf ("%c\n",ch-32);
   }
   while ( ch != '\r');
   getch();
}
