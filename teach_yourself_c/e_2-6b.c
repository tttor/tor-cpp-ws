#include <stdio.h>
#include <conio.h>

int main (void)
{
    int n;
    printf ("enter a number  ");
    scanf("%d",&n);
    
    for (n>0;n>-1;n--) printf ("\t%d\n",n);
    
    printf ("\a");
getch();
}
