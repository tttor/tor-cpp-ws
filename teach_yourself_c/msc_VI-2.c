#include <stdio.h>
#include <conio.h>
int main (void){
    int i,*p ;
    char *c,str[80]="thsvgtor";
    
    p=&i;
    *p=77;
    
    printf("%d\n",i);
    p=str;
    printf ("%c\n",*(p));
    printf ("%c\n",*(p+1));
    printf ("%c\n",*(p+2));
    printf ("%c\n",*(p+3));
    printf ("%c\n",*(p+4));
    printf ("%c\n",*(p+5));
    printf ("%c\n",*(p+6));
    printf ("%c\n",*(p+7));
    getch();
}
 
 
