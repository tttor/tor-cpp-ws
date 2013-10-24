#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i,j,k;
   for (i=0;i<3;i++)
      for (j=0;j<26;j++)
         for (k=0;k<3;k++)
            printf ("%c",'A'+j);
            
   getch();
}
