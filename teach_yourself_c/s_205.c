#include <stdio.h>
#include <conio.h>
#include <string.h>

int init(int x);//this is prototype

int count;//glocab var

int main (void){
    int *p;
    
    p=init(110);//give the function's value
    printf ("count (through p) is %d",*p);
    
    getch();
    return 0;
    
}
int init(int x){
    count=x;
    
    return &count;
}
    
