#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    int i;
//     scanf ("%s",&argc);
        gets(argc);
        if (argc!=3) {
        printf ("retype!!");
        exit(1);
    }
    i=strcmp(argv[1],argv[2]);
    if (i<0) printf ("%s > %s",argv[2],argv[1]);
    else  if (i>0) printf ("%s > %s",argv[1],argv[2]);
    else printf ("same");
    
    getch ();
    return 0;
}
