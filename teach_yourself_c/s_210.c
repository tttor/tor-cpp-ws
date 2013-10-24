#include <stdio.h>
#include <conio.h>
#include <string.h>

void f2(int b);
void f1 (int a);

int main (void){
    f1(30);
    
    getch();


}
//MUTUAL RECURSIVE

void f1 (int a){
    if (a) f2(a-1);//IF A IS NOT ZERO IT'S TRUE
    printf ("%d ",a);
}

void f2 (int b){
    printf ("> ");
    if (b) f1(b-1);
    
}

