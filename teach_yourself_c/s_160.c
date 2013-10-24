#include <stdio.h>
#include <conio.h>

int main (void)
{
   char text [10][80];
   int i;
   for (i=0;i<10;i++)
      { printf ("%d",i+1);
        gets (text [i]);
      }
   do
      { printf ("enter number of string  ");
        scanf ("%d",&i);
        i--;
        if (i>=0 && i<10) printf ("%s\n", text [i]);
      }
   while (i>=0);
   
   //getch();
}
        
