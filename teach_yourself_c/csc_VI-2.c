#include <stdio.h>
#include <conio.h>
#include <string.h>
int main (void)
{
    char str [80],*p,*v="vektor",sta[8];
    int spaces;
    
    strcpy(sta,"ABCDEFG");
    printf ("%c\n",*(sta+2));//USE POINTER TO ACCESS THE CONTENT OF ARRAY!
    //printf ("%s",*v); // why does this line not work???
    
    printf ("enter strings..");
    gets (str);
    
    spaces=0; //initialize the value of spaces=...?
    p=str; // define pointer as array
    
    while (*p){ //during p
        if (*p==' ') spaces++;
        p++;//increment p
    }
    
    printf (" %d spaces",spaces);
    
    getch();
}
