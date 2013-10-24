// ch 1 exercise!!!!
#include <stdio.h>
#include <conio.h>

int main (){
 /*  // 1.14-9
   int *p;
   int array[3]={1,2,3};
   int x,y;
   
   p=array;
   x=*p++;
   y=*p++;
   
   printf ("x=%d;y=%d",x,y);
 */
 /*
  //1.14-10
   int init[6]={21,22,23,24,25,26};
   int result[6];
   int i;
   
   for (i=0;i<6;i++){
      result[i]=init[i]*init[i];
      
      printf("%3d %7d\n",init[i],result[i]);
   }//end for
 */
 
  //1.15-2 till 3
   int x,y,z;
   int q;
   
   printf ("enter x ");
   scanf("%d",&x);
      printf ("enter y ");
   scanf("%d",&y);
      printf ("enter z ");
   scanf("%d",&z);
   
   if((x<=50)&&(y<=50)&&(z<=25)){
       q=x*y*z;
           printf("q=%d",q);
    }//end if
    
   
   else printf("the input exceeds!!");
   
     
   getch();
   return 0;
}
