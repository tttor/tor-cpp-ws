#include <stdio.h>
#include <conio.h>

int main (void){
    /*char ch;
    
    ch=getch();
   printf ("%d",ch); */
    do{
        printf ("%c",'.');
    }while (!kbhit());//while !=0, kbhit is zero when the keystroke pended
    getch();
}
