#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void){
   char phone[][2][40]={
   "bapak","081328807072",
   "rumah","646665"};
   
   int i;
   
   char name[80];
   
   printf ("name ");
   gets (name);
   
   for (i=0;i<3;i++){
      if (!strcmp(name,phone[i][0])) printf ("%s",phone [i][1]);
   }
   
   getch();
}
