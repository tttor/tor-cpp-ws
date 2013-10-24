#include <stdio.h>
# include<conio.h>

int main(void)

{
    float v;
    int p;
    
    printf ("enter value ");
    scanf ("%f",&v);
    
    printf ("1.f 2 m    2.m 2 f");
    printf("   so  choice  ");
    scanf ("%d",&p);
    
    if (p==1) printf ("thus: %f m", v/3.28);
    if (p==2) printf ("thus: %f f", v*3.28);
    
    getch();
    }
