#include  <stdio.h>

#include <conio.h>

int get_sqr(void);

int main(void)
{
    int sqr;
    
    sqr=get_sqr();
    printf("square (ni malahan fs 1st, ddapat dari return'valus):%d",sqr); /* %d di barsis ini adalah mewaili var sqr, ingta typenya adalah int*/
    
    getch();
    return 0;
}

int get_sqr(void)
{
    int num;
    printf ("enter ur number:  ");
    scanf ("%d",&num);
    printf("result=%d        ",num*num);

    return num-1; /*paling akhir dieksekusi*/
}

