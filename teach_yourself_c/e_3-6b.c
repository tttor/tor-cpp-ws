#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i;
   char ch;
   
   for (i=0;i<10;i++)
   {
      printf ("\n enter a letter: ");
      ch=getche ();
      
      printf("\n");
      
      for (ch=getche;ch;ch--) printf ("%c".'.');
   }
   getch();
}
