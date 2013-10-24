#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void){
   char str[80];
   
   do{
      printf ("enter a string : ");
      gets (str);
      }
   while (strcmp ("quit",str));
   
   getch();
   }
