#include <stdio.h>
#include <conio.h>

int main (void){
/*
   // EXAMINE ARRAY 1
   char str[10]="Vektor";
   int *p,i;
   
   printf ("%c",str[4]);
   /*
   //p=str;
   p=&str[0];// same as above !!
   
   for (i=0;i<10;i++){
      printf("%s\n", str[i]);
   }//endof FOR
   
   for (i=0;i<10;i++){
      printf("%s\t", (*p++));
   }//endof FOR
   */

//EXAMINE ARRAY 2
   char day [7][10]={"sun","mon","tue","wed","thurs","fri","sat"};
   //char key [4][3]={'1','2','3',
     //               '4','5','6'};
   char key [4][3]={{'1','2','3'},{'4','5','6'}};
  
   printf ("%s\n",&day[2][0]);//same as below
   printf ("%s\n",day[2]);
   printf ("%c\n\n",day[1][1]);

   printf ("%c",key[0][2]);

//POINTER TO FUNCTIONS
      
   getch();
   return 0;
   
}//endof main
