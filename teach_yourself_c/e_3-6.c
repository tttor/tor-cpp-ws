// find prime number

#include <stdio.h>
#include <conio.h>

int main (void)
{
   int i,j,prime;
   
   for (i=2; i<100;i++)
   {
      prime=1;
      for (j=2;j<=i/2;j++) if (!(i%j)) prime=0;
      if (prime) printf ("%d is prime\n",i);
   }
   getch();
}


