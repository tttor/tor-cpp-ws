#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void) {
   char key[]="vektor";
   char temp[]="------";
   char guess;
   int i,count;

   count = 0;
   
   do{
      printf ("%s\n", temp);
      printf ("ur guess ");
      guess= getche();
      printf ("\n");
   
      for (i=0;i<strlen (key);i++){ 
      if (guess==key[i]) temp[i]=guess;
      count++;}
      }
   while (strcmp(temp,key));
   
   printf ("%s\n", temp);
   printf (" %d",count); // count var is still wrong!!!
   
   getch();
   }
      
   
