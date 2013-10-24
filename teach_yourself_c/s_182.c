#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void){
   char str1[80];//="vektor dewanto";
   char str2[80],*p1,*p2;
   
   printf ("enter the words : ");// make it possiblle to change easily
   gets (str1);//READ WHAT FOLLOWS :....
   p1=str1+strlen(str1)-1;//p point to end of str1; -1 BCOZ THERE IS NULL TERMINATOR
   
   p2=str2;// CONVEY THAT POINTER POINT TO ARRAY
   
   while (p1 >=str1)// do while the value more or equel than the 0th of str
   *p2++=*p1--;
   
   *p2='\0';
   
//   printf ("%s\n",str1);
   printf ("%s ",str2);
   
   getch();
}

