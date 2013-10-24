#include <stdio.h>
#include <conio.h>

int main (void)
{
   int base,exp,y;
    char ch;
   do 
   {  
   printf ("enter the base  ");
   scanf ("%d",&base);
   printf ("enter the exp  ");
   scanf( "%d",&exp);
   
   y=1;
   for (;exp>0;exp--) y=y*base;
   
   printf("result %d\n", y);
   
   printf("continue ?");
   ch=getche();
   printf("\n");
   }
   while (ch!='e');
   
   getch();
}
