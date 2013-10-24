#include <stdio.h>
#include <conio.h>



#pragma warn-

//#define ON
#define OFF

//#error thisiserroe
int main (void){
   int x,i;
   
   printf ("enter ");
   scanf ("%d",&x);
   
 
#ifdef ON//true if DEFINED
 for (i=0;i<5;i++){
      printf ("u've wrote %d %s %s",x,"_TIME_","yeah\n");
   } 
#endif

#ifndef ON
   printf ("u're ON with off-mode");
#endif

#ifndef OFF// true if NOT defined!!
   printf ("u choose OFF");
#endif

   getch();
   return 0;
   
}
