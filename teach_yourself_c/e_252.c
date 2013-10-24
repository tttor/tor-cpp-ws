#include <stdio.h>
#include <conio.h>

int main (void){
    /*
    int i,j;
    printf ("enter ");
    scanf ("%3d%d", &i,&j);//waoww : it assigns the 4th number to the j variable!!!
    printf ("%d %d", i, j);
    
    int i;
    printf ("enter ");
    scanf ("%3d", &i);//waoww : it assigns the 4th number to the j variable!!!
    printf ("%d ", i);
    */
    int i,j;
    printf ("enter the decimal");
    scanf ("%d.%d",&i,&j);// the DOT betweem two %d really must be typed when entering number ot it'LL be any errors
    printf ("left:%d  right:%d", i,j);
    
    getch();
}
