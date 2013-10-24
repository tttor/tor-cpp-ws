#include <stdio.h>
#include <conio.h>
# include <string.h>
   
int main (void)
{
   char english[80];
   int i;
   
   
char word [][2][40]= //40 buat apaan???
   {
      "i","aku",
      "he","dia cow",
      "love","cinta",
   };
   char ch;
   
   do
   {
   printf ("english ");
   gets (english);
   
   i=0;
   
   while (strcmp (word [i][0],"")) // ini berarti selama wntryword greater than null terminator or its value is nor zero meeaning false
      {
        if (!strcmp(english,word[i] [0]))
                {
                  printf("  %s\n",word [i][1]);
            
                  break;
                }
        i++;
      }
          printf ("y/n ");
                  ch=getche;}
                  
                  while (ch!='n');
   
   getch();
}


