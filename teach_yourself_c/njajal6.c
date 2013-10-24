#include <stdio.h>
#include <conio.h>

int main(void)
{
   int i;
   goto mine;
   
   for (i=1;i<50;i++)
   {
      if (!(i%6)) printf ("%d\n",i);
   }
   
   mine:
   printf ("pake goto");
   getch();
}
