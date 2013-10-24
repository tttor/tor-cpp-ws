#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define FUN "vektor\n"//just a simple text replacement
#define ONE 1
#define TWO ONE+1//this is actually added
int main (void){
    char ch,ce;
    
    printf (FUN);
    printf ("%d %d",ONE, TWO);
    do {
       ch= getchar();//act as line buffer
       putchar("?");
    }
    while (ch!='\n');
    
    do{
        ce=getch();
        }
        while(ce!='q');

   getch();
}

