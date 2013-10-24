#include <stdio.h>
#include <conio.h>

int main (void)
{
   int ball [4][5],i,j;
   
   for (i=0;i<4;i++)
      for (j=0;j<5;j++)
      {
      printf (" quarter %d ; player %d\n", i+1,j+1);
      printf ("enter number of points");
      scanf ("%d",&ball [i][j]);
      }
      
      // display result
      
   for (i=0;i<4;i++)
      for (j=0;j<5;j++)
      {
            printf (" quarter %d ; player %d scores %d\n", i+1,j+1,ball [i][j]);
            
      }
      
   getch ();
}

