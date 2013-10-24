#include <stdio.h>
#include <conio.h>

int  main (void)
{
   int i,j;
   
   for (i=0;i<10;i++)
   {
      for (j=i;j<11;j++) printf ("%d",j);
      printf("\n");
   }
   getch();
   
}
