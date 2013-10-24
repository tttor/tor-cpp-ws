#include <stdio.h>
#include <conio.h>
#include <string.h>

int fact(int i);


int main (void){
        int x;
printf ("number: ");
  scanf("%d",&x);
    
    printf ("facC OF 4 is %d",fact(x));//,fact(i));
    //printf ("%d",fact(4));
    getch();
    return 0;
}

int fact (int i){
    //i=x;
    if (i==1) return 1;
    else return i*fact(i-1);
}
