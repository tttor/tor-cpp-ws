#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i;
   
   printf ("i= ");
   scanf("%d",&i);
   switch (i)
      {
         case 1: printf ("a=1\n");
         case 2:printf ("a=2\n");
         break;
         case 4:
         case 5: printf ("a=5");
      }
   getch();
}
  
