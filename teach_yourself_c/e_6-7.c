/*this is parameterized the pointer*/
#include <stdio.h>
#include <conio.h>

int main (void){
    int i;
    
    f (&i);
    printf ("%d",i);
    getch();
}
void f (int *p){
    *p=-1;
}
