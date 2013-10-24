#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
    FILE *fp;
    char ch;
    
    if (argc !=2){
        printf ("file name is missing\n");
//        exit (1);
    }
    
    if ((fp=fopen(argv[1],"r"))==NULL){
        printf ("can not open\n");
  //      exit (1);
    }
    
    while ((ch=fgetc(fp))!=EOF) putchar(ch);
    
    fclose(fp);
    
    getch();
}
