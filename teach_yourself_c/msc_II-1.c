#include <stdio.h>
#include <conio.h>

int main (void)
{
    int g,k,i;
    
    k=17;
   
    g=1;
    
    
    
    for (i=1;i<11 && g!=k;i++)
        {
        printf ("this is ur %dth guess \n",i);
        printf ("ur=  ");
        scanf ("%d",&g);
        
        if (g==k)  printf ("win");
          else {
                if (g>k) printf ("ur is too big\n\n");
                else  printf ("ur is too small\n\n");
                    }
                        
        
        }
getch();
}
    
    
