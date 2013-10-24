#include <stdio.h>
#include <conio.h>

int main (void)
{
   char ch;
   printf ("enter\n");
   
   ch=getche();
   while (ch!='\r')
   {
      printf("%c\n",ch+1);
      ch=getche();
   }
   
}
   
