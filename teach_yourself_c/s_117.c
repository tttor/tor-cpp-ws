#include <stdio.h>
#include <conio.h>

int power(int m,int e); // prototype

int main  (void)
{
   int m,e;
   
   m=2;
   e=3;
   
   printf ("%d pangkat %d is %d \n",m,e,power(m,e));
   printf (" 4 pangkat 5 is %d\n",power(4,5));
   printf ("3 pangkat 3 is %d\n",power (3,3));
   
   getch();
}

int power (int m, int e)
{
   int temp;
   temp=1;
   for(;e>0;e--) temp=temp*m;
   
   
}
