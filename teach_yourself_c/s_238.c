#include <stdio.h>
#include <conio.h>

int main (void){
    double amount;
    amount=0.20;
    
    cprintf ("print table\n");
    cprintf ("press key \n\n");
    
   /* do {
        cprintf(" amount=%f, tax: %f\n\r",amount,amount*0.5);
        if (kbhit()) break;
        amount =amount + 0.20;
    } while (amount < 100.0);*/
    getch();
    return 0;
}
