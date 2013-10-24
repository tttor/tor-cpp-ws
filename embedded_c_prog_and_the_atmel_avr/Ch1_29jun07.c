#include <stdio.h>
#include <conio.h>
//#include <90s8535.h>

int main (){
   enum {zero=2, one,two};
   int x=150,z;
   char y=63;
   const p=9; 
  // x=two;
   //printf (" two !=%d",x);
   
   z=((int)y*10)+x;// this is typecasting....
   printf (" z= %d\n",z);
   p=7;
      printf (" p= %d\n",p);
   getch();
   return 0;
}
