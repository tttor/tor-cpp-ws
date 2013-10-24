#include <stdio.h>
#include <conio.h>

int main (void)
{
   char num [10][15]={
   "zero",
   "one",
   "two",};
  
   char input,temp,again;
   int i;
   
   do{
   
   printf ("enter num= ");
   input=getch();
   
   
   
    if (input>0) 
        {
                temp=input-'0';
                printf (num[temp]); 
   }
   printf ("\n");
   printf(" again\n");
   again=getch();
   }
   while (again!='n');
   //getch();
}
