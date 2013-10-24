#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main (void){
    char str [80] ="this is a file system test made by beginner:t0R \n"; // direct definition for array
    FILE *fp;
    char *p;
    char ch;
    int i;
    
    // open my file for output
    if ((fp = fopen ("myfile","w"))== NULL){
        printf ("canot open the file\n");
        exit (1);
    }
    
    //write str to disk$
    p=str;
    while (*p){
        if (fputc (*p++,fp)==EOF){
                printf ("error writing file\n");
                exit (1);
        }
    }
    fclose(fp);
    
    //open the file FOR READ
    if ((fp=fopen("myfile","r"))==NULL){
        printf ("cannot open file\n");
        exit (1);
    }
    
    //read back the file
    while ((ch=fgetc(fp)) !=EOF) putchar (ch);
    /*for(;;){
        i=fgetc (fp);
        if (i==EOF) break;
        putchar(i);
    }*/
    fclose(fp);

    
    getch();
    return 0;
}
