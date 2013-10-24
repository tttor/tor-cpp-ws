#include <stdio.h>
#include <conio.h>

#define SUM(j,k) j+k
#define MUL(a,b) a*b //ATTENTION : PARAMETER CAN BE PASSED IN TO #DEFINE
#define print_mssg(t) printf(#t);
#define VOLUME(a,b,c) a*b*c
#define LOVE_MSSG "bunga i love u\ 
u so beautiful" 
//above is not match with what said at page 180: the line is broken
//#ifdef ONE 
  // [x=2]/
//#endif

//#error this is error
int main (){
/*
   //EXAMINE SPRINTF
   char str[10];
   
   sprintf (str,"vektor");//ACTUALLY SAME AS PRINTF, EXCEPT THAT THE OUTPUT
                           // IS STORED IN THE ARRAY str INSTEAD OD  PRINTED ON THE SCREEN
   puts(str);
*/
/*
   //EXAMINE GETS
   char s[12];
   
   gets (s);//DON'T EXCEED THE SIZE OF ARRAY!!!!
   //puts(s);
*/
/*
   //EXAMINE SSCANF
   char s[12]="1234";
   int x;
   
   sscanf(s,"%d",&x);//same as sprintf
   
   printf ("\n%d",x);
   
   //puts(s);
*/

   //EXAMINE THE USEFULNESS n flexibility OF #define
   int x,y,z;
//   char s[100]={
   x=SUM(3,4);
   y=MUL(4,5);
   z=VOLUME(2,3,4);
   printf ("%d\n",x);
   printf ("%d\n",y);
   printf ("%d\n",z);
   print_mssg(wah hebat bgt- jd more n more readable\n)
   printf (LOVE_MSSG);
   
   //putsf(_TIME_);
   
   getch();
   return 0;
}
