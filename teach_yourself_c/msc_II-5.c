#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i,v;
   for (i=1;i<101;i++) 
   {
      printf("%d\t",i);
      if ((i%5==0)) printf ("\n");
   }
   getch();
}
