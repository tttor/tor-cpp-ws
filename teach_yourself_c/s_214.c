
#include <stdio.h>
#include <conio.h>
#include <string.h>

void prompt(char *msg,int *num);

int main (void){
    int i;
    prompt("enter number : ",&i);
    printf ("yours is %d",i+1);
    getch();
    return 0;
}

void prompt (char *msg,int *num){
    printf (msg);
    scanf ("%d",num);
}
