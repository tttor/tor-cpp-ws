#include <stdio.h>
#include <conio.h>

int  main (void)
{
   char fr;
   float lit,gal;
   
   do
   {
   printf ("from L/G/S for stop\n");
   fr=getche();
   printf("\n");
   
   if (fr=='l')
   {
      printf("how many liters? ");
      scanf ("%f",&lit);   
      printf ("so %f gallon\n",lit/3.785);
   }
    else if (fr=='g')
   {
      printf("how many gallons? ");
      scanf ("%f",&gal);   
      printf ("so that is %f litter\n",gal*3.785);
   }
   }
   while ( fr!='s');
   
   printf ("thx");
   getch();
}
