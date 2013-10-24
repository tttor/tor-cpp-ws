#include <stdio.h>
#include <conio.h>

int main (void)
{
   int sqcub [10] [3],i,j;
   
   for (i=0;i<10;i++)
      for (j=0;j<3;j++)
            { 
              sqcub [i][0]=i+1;
              sqcub [i][1]=(i+1)*(i+1);
              sqcub [i][2]=(i+1)*(i+1)*(i+1);
              }
   for (i=0;i<10;i++)
      {
            for (j=0;j<3;j++)
            printf ("%d",sqcub[i][0]);
   }
getch();
}
              
