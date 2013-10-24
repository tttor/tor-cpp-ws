#include <stdio.h>
#include <conio.h>

int main (void){
    char *p,str[80];
    
    puts ("one");
    puts ("two");//no neef \n 4new line
    
    printf ("enter");
    p=gets (str);
    if (p) //if not nuLL terminator
    printf ("%s............%s",p,str);
    
    getch();
    return 0;
}
