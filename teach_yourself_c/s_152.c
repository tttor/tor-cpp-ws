#include <stdio.h>
#include <conio.h>

int main (void)
{
   int twod [4][5];
   int i,j;
   
   for (i=0;i<4;i++)
      for (j=0;j<5;j++)
      twod [i][j] = i* j; // define how contents are created , of array 2-d ( means each entry has 2 values)
   
      for (i=0;i<4;i++)
      {
            for (j=0;j<5;j++)
            printf ("%d ",twod [i][j]);
     //       printf ("\n");
      }
   getch();
}

