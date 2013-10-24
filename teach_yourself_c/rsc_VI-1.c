#include <stdio.h>
#include <conio.h>

int main (void){
   int sum[10],i,odd,even,j;
   
   printf ("enter 10 number ");
   
   even=0;
   odd=0;
   
   for (i=0;i<10;i++) scanf("%d",&sum[i]);
  
   for (i=0;i<10;i++){
      
      if (!sum[i]%2 ) even=even+sum[i];
      else odd=odd+sum[i];
   } 
   
   
   printf ("sum of %d and %d", even,odd);
   
   
   getch();
}
