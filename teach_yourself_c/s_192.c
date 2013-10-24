#include <stdio.h>
#include <conio.h>
void myputs (char *p);

int main (void)
{
    myputs ("this is test");
    
    getch();
}
void myputs (char *p)
{
    while (*p)
    {
        printf ("%c",*p);
        p++;
    }
    printf ("\n");
}
