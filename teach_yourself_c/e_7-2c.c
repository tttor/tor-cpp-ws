#include <stdio.h>
#include <conio.h>
#include <string.h>

void display(char *p);

int main (void){
    display ("vektor");
    
    getch();
    return 0;
}
void display (char*p){
    if (*p){
        printf ("%c",*p);
        display (p+1);
    }
}
