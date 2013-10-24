#include <stdio.h>
#include <conio.h>

int main (void){
   int a[10]={1,2,3,4,5,6,7};
   int *p;
   
   p=a;
   printf ("%d %d", *p,*(p+1));
   
   getch();
} 
