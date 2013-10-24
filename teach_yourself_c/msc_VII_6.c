#include <stdio.h>
#include <conio.h>
#define COUNT 50
int main (void){
    int i;
    
    /*for (i=0;i<COUNT;i=i+10) printf ("%d \a\n",i);
    printf ("\a");  */
    
    printf ("%d\n%n",100,&i);//%n for counting the number of wrtten characters, the new line "\n"is counted as one character
    printf ("%d character output so far",i);  
    
    getch();
}
    
