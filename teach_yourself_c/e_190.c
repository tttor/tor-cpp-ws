#include <stdio.h>
#include <conio.h>

int main (void){
    int i,*p,**s;
    
    p=&i;
    s=&p;
    
    **s='99';
    
    printf ("%s",*s);
    printf ("\n");
    printf ("%p %p %p", &i, p, s);//show the address
    
    getch();
}
