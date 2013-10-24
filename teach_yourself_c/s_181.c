#include <ctype.h>
#include <stdio.h>
#include <conio.h>

int main (void){
   char str[80],*p;
   
   printf ("enter strings ");
      gets (str);
   p=str;
   
   while (*p){
      *p++=toupper(*p);
   }
   
   printf ("%s\n",str);
   
   getch();
}
