#include <stdio.h>
#include <conio.h>

int main (void){
    char name [9][80];
    double b_avg[9];
    int i,h,l;
    double high, low, team_avg;
    
    for (i=0;i<3;i++){
        printf ("enter name %d ", i+1);
        scanf ("%s", name [i]);
        printf ("entr batting avg: ");
        scanf ("%lf",&b_avg [i]);
        printf ("\n");
    }
    
    high=0.0;
    low=1000.0;
    team_avg =0.0;
    for (i=0;i<3;i++){
        if (b_avg[i]>high) {
                h=i;
                high = b_avg [i];
        }
        if (b_avg[i]<low){
                l=i;
                low = b_avg [i];
        }
       team_avg = team_avg+b_avg[i];
    }
printf ("the h is %s %f \n", name [h], b_avg[h]);
     printf ("the L is %s %f \n", name [l], b_avg[l]);
 printf ("team average %f", team_avg/3.0);
     
  getch();
} 
