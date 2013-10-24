#include <stdio.h>
#include <conio.h>
#include <string.h>
int main (void){
   char pw[80];
   int i;
   
   for (i=0;i<3;i++){
      printf ("password ");
      gets (pw);
      if (!strcmp("vektor",pw)) break;
   }
   
   if (i==3) printf ("access denied");
   else printf ("log on");
   
   getch();
}
