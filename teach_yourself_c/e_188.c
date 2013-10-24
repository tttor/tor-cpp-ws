#include <stdio.h>
#include <string.h>
#include <conio.h>

int main (void){
   char *p[3]={//this is array of pointer
      "modulusya 0","modulusya 1","modulusya 2"};// this line is initialization
   char str[80];
   int i;
   for (i=0;1<10;i++){   
   printf ("enter questions...  \n");
   gets (str);
   
   printf (p[strlen(str)%3]);//print the valur of arry of pointer which address is inside[]
   }
   getch();
   }
