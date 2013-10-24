#include <stdio.h>
#include <conio.h>
#include <string.h>
float genum (void){
    float x;
    printf ("enter ");
    scanf("%f",&x);
    return x;
}

int main (void)
{
    float i;
    
    i=genum();
    printf ("%f",i);
    getch();
    return 0;
    
}
