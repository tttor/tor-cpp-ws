#include <stdio.h>
#include <conio.h>

int  main (void)
{
   int i;
   for(i=1;i<101;i++)
   {
      if (!(i%2)) continue;
      printf ("%d\n",i);
   }
   getch();
}
