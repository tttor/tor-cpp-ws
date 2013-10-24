#include <stdio.h>
#include <conio.h>

int main (void)
{
    int i,j;
    
    printf ("1st= ");
    scanf ("%d",&i);
    
    printf ("2nd=  ");
    scanf ("%d",&j);
    
    printf ("i<j %d \n", i<j);
    printf ("i>j %d \n", i>j);
    
    printf ("i && j %d \n", i&& j);
    printf ("i ||j %d", i||j);
    
getch();
}
