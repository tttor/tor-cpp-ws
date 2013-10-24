#include <stdio.h>
#include <conio.h>

int main (int argc, char *argv[]){
    int i,n;
    printf ("enter number");
    scanf ("%d",&n);
    
    for (i=1;i<argc;i++) printf ("%s",argv[i]);
    
    getch();
}
