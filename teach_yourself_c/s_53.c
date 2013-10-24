#include  <stdio.h>
#include<conio.h>

int main(void)
{
    int num,i,p;
    
    printf ("number  ");
    scanf ("%d",&num);
    
    p=1;
    
    for (i=2;i<=2;i=i+1) if ((num%i)==0) p=0;
    
    if (p==1) printf("prime");
    else printf ("not");
    
    getch();
}
