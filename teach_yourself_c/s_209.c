#include <stdio.h>
#include <conio.h>
#include <string.h>

void rcopy (char *s1,char *s2);

int main (void){
    char str[80];
    
    rcopy(str,"this is vektor");
    printf (str);
    
    getch();
    return 0;
}

void rcopy (char *s1,char *s2){
    if (*s2){
        *s1++=*s2++;
        rcopy (s1,s2);
    }//else *s1='\0';
}
