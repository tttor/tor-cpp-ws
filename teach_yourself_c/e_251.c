#include <stdio.h>
#include <conio.h>

int main (void){
    int i,j;
    char op;
    
    printf ("enter operation:");
    scanf ("%d %c%d",&i,&op,&j);// take  a look at the SPACE between "", it's really a matter
    
    switch(op){
        case '+': printf ("%d",i+j);
                break;
        case '=': printf ("d",i-j);
                break;
        case '*': printf ("%d",i*j);
                break;
        case '/': printf ("d",i/j);
                break;
    }
    
    getch();
}
