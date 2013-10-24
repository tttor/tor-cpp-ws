#include <stdio.h>
#include <conio.h>

int  main (void)
{
   char lt;
   do 
   {
      printf ("enter one letter\n");
      lt=getche();
      printf ("\n");
   }
   while (lt!='v');
   
   if (lt=='v') printf ("right");
   
   getch();
}

