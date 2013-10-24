#include <stdio.h>
#include <conio.h>

int main (void)
{
   int server  [5][2]=
      {
         1,14,
         2,32,
         3,54,
         4,65,
         5,66
      };
   
   int serv,i,chance;
   
   for (chance=0;chance<5;chance++)
   {
   printf ("server no. ");
   scanf ("%d",&serv);
   
     
   for (i=0;i<5;i++)
      if (serv == server [i][0])
            {
               printf ("there are %d users\n",server [i][1]);
   //            break;
            }
   }
   
   getch();
}
