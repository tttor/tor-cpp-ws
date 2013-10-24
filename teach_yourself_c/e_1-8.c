#include <stdio.h>
#include <conio.h>

int convert(void);

int main(void)
{
    printf("%d",convert());
    
    getch();
}

int convert (void)
{
    int dollar;
    printf ("enter ur dollar ");
    scanf ("%d",&dollar);
    
    printf ("so u have %d puound= ",dollar/2);
//   return dollar; 
}

