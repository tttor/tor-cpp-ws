#include <stdio.h>
#include<string.h>
#include<conio.h>

int main(void)
{
   char back[100];
   int i;
   
   gets (back);
   
   i= strlen(back)-1;
   
   
   for (;i>=0;i--) printf("%c",back[i]);
   
   getch();
}
