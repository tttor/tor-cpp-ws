#include<stdio.h>
#include <conio.h>
#include<stdlib.h>

int main (void)
{
   char at[8];
   int i;
   printf (" %s %s %s", "i", "love" ,"u");
   
   gets(at);
   i=atoi(at);
   
    printf ("\n%d",i); 
   
   getch();
}
