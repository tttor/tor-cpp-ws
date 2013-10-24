#include  <stdio.h>
#include<conio.h>

int main(void)
{
    int sum,num,prod;
    
    sum=0;
    prod=1;
    
    for (num=1;num<6;num=num+1) 
        {
        sum=sum+num;
        prod=prod*num;
        }
        printf ("product and sum: %d  %d",prod,sum);
        
    getch();
}
