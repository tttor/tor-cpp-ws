#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i;
   char ch;
   
   for (i=1;i<1000;i++)
   {   
      if (!(i%6)) printf ("%d\n ",i);
      
   }
   getch();
}
