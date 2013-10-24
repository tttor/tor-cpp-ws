#include<stdio.h>
#include <conio.h>


int main (void)
{
   int item[100],a,b,t,count;
   
   printf ("how many numbers  ");
   scanf ("%d",&count);
   for (a=0;a<count;a++) scanf ("%d",&item[a]);
   
   for (a=1;a<count;a++) for (b=count-1;b>=a;b--)
      {
            if (item[b-1] > item[b])
               {
                 t=item[b-1];
                 item [b-1]=item [b];
                 item[b]=t;
               }
      }
      
   for (t=0; t<count; t++) printf ("%d",item[t]);
   
   getch();
}
