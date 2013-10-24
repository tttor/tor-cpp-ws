#include <stdio.h>
#include <conio.h>
#include <string.h>

double avg (void);

int main (void)
{
    printf ("%f",avg());// attention how we print the alue of function
    getch();
  }
  
double avg (void){
    int i;
    double sum, num;
    sum=0.0;
    for (i=0;i<10;i++){
        printf ("enter number : ");
        scanf("%lf",&num);
        sum=sum+num;
    }
    
    return sum/10.0;//this the last value of avg with return 
} 
