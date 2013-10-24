#include <stdio.h>
#include <conio.h>

int main (void) {
   char str[80],*p;
   
   printf ("enter string :  ");
   gets (str);
   
   p=str;
   
   while (*p && *p!=' ') p++;//*p while the p's value is exist and *p not space thus p++
   printf (p);
   
   getch();
}
