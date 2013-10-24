#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void){

   int stat [20],i,j,mode,count,oldcount,oldmode;
   
   printf ("enter 20 numbers: ");
   
   for (i=0;i<20;i++) scanf("%d",&stat[i]);
   
   oldcount=0;
   
   for (i=0;i<20;i++) {
      mode=stat[i];
      count=1;
      
      for (j=i+1;j<20;j++)
            if (mode==stat[j]) count++;
            
            if (count>oldcount) {
              oldmode=mode;
              oldcount=count;
              }
      }
      printf ("the mode id %d",oldmode);        
         getch();
}
