#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i;
   
   printf( "how long....");
   scanf("%d",&i);
   
    for (;i;i--) printf ("\a");
    printf ("finish");
    getch();
}
