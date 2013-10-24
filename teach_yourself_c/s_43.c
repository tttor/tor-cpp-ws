#include <stdio.h>
#include<conio.h>

int main (void)

{
    int answer;
    
    printf (" 1+1 =  ");
    scanf ("%d",&answer);
    
    
    if (answer == 2) printf ("right");
    if (answer > 2) printf ("too big");
    
    getch();
    }
