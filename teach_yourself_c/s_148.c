#include <string.h>
#include<stdio.h>
#include <conio.h>

int main (void)
{
   char str1[80],str2[80];
   int i;
   
   printf("1st string ");
   gets(str1);
   printf("2nd string ");
   gets (str2);
   
   printf ("%s is %d chars long\n", str1,strlen(str1)); 
   printf ("%s is %d chars long\n", str2,strlen(str2));
   
   i=strcmp (str1,str2);
   if (!i) printf ("equal");
   else if (i<0) printf ("1s less\n");
   else printf ("1st greater\n");
   
   if (strlen(str1)+strlen(str2) < 80)
   {   
      strcat (str1,str2);
      printf("%s\n",str1);
       }     
   getch();
}
