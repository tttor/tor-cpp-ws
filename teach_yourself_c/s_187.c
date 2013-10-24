#include <stdio.h>
#include <conio.h>
#include <string.h>

char *p[][2]={// define the array of pointer, easily
   "alin","pak ari",
   "optic","suryadarma",
   "mtL","iwa",
   //" ",""
   };

int main (void) {
   int i;
   char clas[80];
   
   printf ("enter class\n");
   gets(clas);
   
   for (i=0;*p[i][0];i++) { // loop for ....  but it is still failed i don;t know why???
      if (!strcmp(clas,p[i][0])) printf (" %s  is %s \n",clas,p[i][1]);
   }
   getch();
}
