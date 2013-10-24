#include <stdio.h>
#include <conio.h>

int main (void){
   char str[80];
   int i[10]={1,2,3,4,5,6,7};
   
   printf ("enter strings ");
      gets (str);
   //p=str;
   
   //*(str+3)='v'; // determine the value of 3rd element on array "str"
   
   printf (" %c\n",*(str+3));
   
   printf ("%d",*(i+6));
   
   getch();
}
