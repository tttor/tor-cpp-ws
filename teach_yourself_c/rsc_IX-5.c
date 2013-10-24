#include <stdio.h>
#include <conio.h>

int main (void){
    char str [80];
    
    printf ("enter  ");
    scanf ("%*[0-9]%s",str);// * means not included/not scanned
    printf ("%s",str);
    
    getch();
}
