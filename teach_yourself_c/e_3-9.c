#include <stdio.h>
#include <conio.h>

int  main (void)
{
   char ch;
   int d,l,p;
   
   printf ("enter any , enter 2 stop");
   
   d=0;
   l=0;
   p=0;
   
   do
   
   {
      ch=getche();
      switch (ch)
      {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
            d++;
            break;
            
            case ',':
            case '.':
            case '/':
            p++;
            
            break;
            default:
            l++;
      }
   }
   while (ch!='\r');

   printf ("\nd =%d\n",d);
   printf("p=%d\n",p);
   printf("l=%d",l);
   
   getch();
}
