#include <stdio.h>
#include <conio.h>

//PROTOTYPES
int fact(int);
int swap(int *pa,int *pb );

int main (void){
/*
   //EXAMINE RECURSIVE METHODE for COUNTING FACTORIAL
   int n,f;
   
   printf ("enter n=  ");
    scanf ("%d",&n);
   
   f=fact(n);
   
   printf (" %d!= %d",n,f);
*/

//EXAMINE THE POINTER 1
/*   int a,b,*p;
   
   a=7;
   p=&a;
   //b=*p;
   b=9;
   *p=b;
   
   printf("b=%d",b);
   printf("\n value of a %d ",*p);   
*/
/*
//EXAMINE THE POINTER 2
   char a,b;
   char *p;
   
   a=7;
   p=&a;
   printf ("before &p= %d\n",&p);
   printf ("before p= %d",p);
   printf ("\nbefore *p=%d",*p);
   
   //b=*p++;// this will cause: 1. the value of memory pointed by p is assigned to b
                           //2. the vcalue of p itself incremented 
   
   //b=++*p;//increment the value of a then assign to b
   
   //b=(*p)++;//assign the value of a to b, then incement the value of a
   
   b=*++p;// the value of p itself is incremented so thar the value of b will unpredictable
   
   printf ("\n b= %d",b);
   printf ("\n&p= %d",&p);
   printf ("\np= %d",p);
   printf ("\n*p=%d",*p);
*/
//EXAMINE THE POINTER 3
   int five,seven;
   
   five=5;
   seven=7;
   
   swap(&five,&seven);
   
   printf (" five=%d\tseven=%d",five,seven);           
   getch();
   return 0;
}
int swap(int *pa,int *pb){
   int temp;
   
   temp=*pb;
   *pb=*pa;
   *pa= temp;
}

int fact(int n){
   if (n==0) return 1;
   else {
      return (n * fact(n-1));
   }
}
