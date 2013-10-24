#include <stdio.h>
#include <conio.h>

int main (void)
{
    int i,e,n1,n2,ua,r,w,t,chance;
    char ch,key;
    r=0;
    w=0;
    t=0;
    printf ("WELCOME TO MULTIPYING DRILL 2007\n by vektor(copyright)\n\n please, enter the key\n");
    
    for (key=getch(); key !='v'; key=getche())
   {
      printf ("\n");
      printf("enter valid key!\n");
 
   }
   if (key=='v')
   {
   printf ("\n");
    for (i=1;i<1000 && ch !='n';i++)
    {
    
        printf (" this is ur %dth drill\n",i);
        printf ("n1= ");
        scanf("%d",&n1);
        printf("n2= ");
        scanf ("%d",&n2);
        printf(" %d x %d =  ",n1,n2);
        scanf("%d",&ua);
        if (ua==n1*n2) 
                {
                                printf ("right\n");
                                r++;        
                }
        else 
                {
                                printf ("wrong\n");
                               
                                w++;
                }
        printf("n/y\n");
        ch=getche();
         printf ("\n");
        
        t=t+1;
    }
    printf ("thanks,\n you have \n\n total right=%d \n and \n total wrong=%d \n from %d drill(s)" ,r,w,t);
    }
    getch();
}
 
