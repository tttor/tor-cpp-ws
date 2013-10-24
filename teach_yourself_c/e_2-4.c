#include  <stdio.h>
#include<conio.h>

int main(void)
{
    int n,i,p;
    
    
    
    printf ("number=  ");
    scanf ("%d",&n);
    
    printf ("the factor(s) are ");
    
    for (i=1;i<9999999999999999999999999999999;i=i+1) 
    {
    if (i<=n) 
                {
                p=n%i;
                
                if (p==0)    printf ("%d,",i);
                }
    }
    
    

    
getch();
}
