#include <stdio.h>
#include <conio.h>

int  main (void)
{
    char fr;
   float lit,gal;
   
   printf ("from L/G/S for stop");
   fr=getche();
   
   if (fr=='l')
   {
      printf("how many liters? ");
      scanf ("%f",&lit);   
      printf ("so that is %f gallon",lit/3.785);
   }
   else if (fr=='g')
   {
      printf("how many gallons? ");
      scanf ("%f",&gal);   
      printf ("so that is %f litter",gal*3.785);
   }
   getch();
}
