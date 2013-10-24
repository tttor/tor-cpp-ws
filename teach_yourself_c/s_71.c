#include <stdio.h>
#include <conio.h>

int main(void)
{
   char ch,c;
   int i;
   
   for (i=1;i<10 && ch != 'n';i++)
   {
      printf("n/y\n");
      ch=getche();
   
      printf("you typed:%c\n",ch);
      if (ch < 'f') printf ("less\n");
   }
   for (c='a';c<='z';c++) printf ("%c"); 
         getch();
   
}
   
