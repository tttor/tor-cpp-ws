#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void) {
   char mssg[80];
   int i,j;
   
   printf ("mssg= ");
   gets(mssg);
   
   i=0;
   j= strlen (mssg)-1; // rememebr there is nuLL terminator
   
   while (i<=j){
      if (i<j) printf ("%c %c", mssg[i],mssg[j]);// must %c b'coz it shows per char, %s to output newline all
      else printf ("%c", mssg[i]);
      i++;
      j--;
   }
   getch();
}
