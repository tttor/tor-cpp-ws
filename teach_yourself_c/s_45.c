#include <stdio.h>
#include <conio.h>

int main(void)
{
    float n1,n2;
    
    
    printf ("1st=  ");
    scanf("%f",&n1);
    
    printf ("2nd=  ");
    scanf ("%f",&n2);
    
    if (n2==0) printf ("error");
    else printf ("%f",n1/n2);
    
    getch();
    }

