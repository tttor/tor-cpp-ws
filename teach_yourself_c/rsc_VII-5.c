#include <stdio.h>
#include <conio.h>
#include <string.h>

int mystarlen (char *p);//pointer as parameter

int main (void)
{
    char str [80];
    
    printf ("enter string");
    gets (str);
    
    printf ("leght is %d",mystarlen(str));//take the vcalue %d from  external function
    
    getch();
}

int mystarlen (char *p){
    int i;
    
    i=0;
    while(*p){
        i++;
        p++;
    }
    return i; // bring back the i value
}
