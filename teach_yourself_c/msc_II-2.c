#include <stdio.h>
#include <conio.h>

int main (void)
{
    int r,w,h,i,t;
    
    printf ("how many room(s)  ");
   
     scanf ("%d",&r);
    printf("\n");
    
    t=0;
    
    for (i=r;i>0;i--) 
   
    {
    printf("%d th rooms \n",i);
   
    
    printf ("1st=  ");
    scanf("%d",&h);
    
    printf ("2nd=  ");
    scanf ("%d",&w);
    
    t=t+h*w;
    }
    
    printf ("area=%d\n", t);
getch();
}

    
    
    
