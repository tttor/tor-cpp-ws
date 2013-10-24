#include <stdio.h>
#include <conio.h>

int main (void)
{
   float r,a,t,s;
   char form,con;
   int i;

   for (i=1;i<1000 && con !='n';i++) 
   {
   printf ("what will you count? c/t/p   ");
   form=getche();
   printf("\n");

   if (form =='c')
   {
      printf ("r= ");
      scanf("%f",&r);
      printf ("area=%f\n",3.1416*r*r);
   }
   else if (form=='t')
   {
      printf ("a=");
      scanf ("%f",&a);
      printf("t= ");
      scanf ("%f",&t);
      printf ("area=%f\n",0.5*a*t);   
   }
   else if (form=='p')
   {
      printf ("l=");
      scanf ("%f",&s);
      printf ("area=%f\n",s*s);
   }
   
   printf ("else y/n ");
   con=getche();
   printf ("\n");
   
   }
   

}
