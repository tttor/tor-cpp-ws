#include <stdio.h>
#include <conio.h>

int main (void)
{
   char mess[80];
   int i;
   
   printf ("nter mess \n");
   
   for (i=0;i<80;i++)
      {
            mess [i]= getche();
            if (mess[i]=='\r') break;
      }
   printf ("\n");
   
   for (i=0;mess [i] != '\r'; i++) printf ("%c", mess[i]+1);
   
   getch();
}
