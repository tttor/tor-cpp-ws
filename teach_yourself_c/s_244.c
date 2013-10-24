#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main (void){
    int i;
    for (i=0;i<1000;i++) printf ("%10d %-10d %10d\n" , rand(),rand(),rand());
    
    printf ("%d %f\n %n", 100,123.34,&i);
    printf ("%d %% char",i);// look how % is written
    
    getch();
}    
