#include <stdio.h>
#include <conio.h>

int main (void)
{
    int p,q;
    
    printf (" p 0/1: ");
    scanf ("%d",&p);
    printf (" q 0/1 : ");
    scanf ("%d",&q);
    
    printf (" p or q = %d\n", p||q);
    printf (" p xor q = %d", xor(p,q));
    
getch();
}

int xor(int a,int b)
{
    return (a||b) && !(a&&b);
    } 
