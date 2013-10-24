#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i;
   
   printf ("integer= ");
   scanf("%d",&i);
   
   for (;i;i--) printf ("%d\n",i);
   
   
   printf("0 \a");
   getch();
}
