#include <stdio.h>
#include<conio.h>

int main(void)

{
    int i;

    printf ("integer= ");
    scanf ("d%",&i);



  if ((i%2)==1) printf ("odd");
else printf ("even");

    getch();
   return 0;
    }
