#include <stdio.h>
#include <conio.h>

int main (void){

    char num[80];
    printf ("enter ");
    scanf ("%[0-9.]",num);// the DOT (used to enter decimal number) must be typed if u want it appears in printf 
    printf (num);
    
    getch();
}
