#include <stdio.h>
#include <conio.h>

int main (void)
{
   int three [3][3][3],i,x,j,k;
   
   x=1;
   
   for (i=0;i<3;i++)
      for (j=0;j<3;j++)
            for (k=0;k<3;k++)
            {
               three [i][j][k] =x;
               
               x++;
               printf ("%d ",three [i][j][k]);
            }
getch();
}
