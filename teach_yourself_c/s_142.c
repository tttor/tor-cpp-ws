#include <stdio.h>
#include <conio.h>

int main (void)
{
   int temp[31],i,min, max,avg, days;
   
   printf ("how many days  ");
   scanf ("%d",&days);
   
   for (i=0;i<days;i++)
      {
            printf ("enter temp for day %d  ",i+1);
            scanf ("%d",&temp[i]);
      }
   
   avg=0;
   for (i=0;i<days;i++) avg=avg+temp[i];
   
   printf ("avg tenp is %d\n",avg/days);
   
   min=200;// max value
   max=0;// min value
   
   for (i=0;i<days;i++)
      {
            if (min>temp[i]) min=temp[i];
            if (max<temp[i]) max=temp[i];
      }
   printf ("min temp is %d\n", min);
   printf ("max temp is %d", max);
   
   getch();
}
