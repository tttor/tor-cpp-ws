#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main (int argc,char *argv[]){
    double pond;
    
    pond= atof (argv[1]) / 16.0;
    printf ("%f pound",pond);
    
    getch();
}
