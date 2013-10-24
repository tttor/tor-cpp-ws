//hex to binary CONVERTER
//unsuccesful YET 6juL07;8.35a
#include <stdio.h>
#include <conio.h>

int putbin(int x){
   int k;
   for (k=0;k<2;k++){
      if (x & (1<<k)) putchar('1');
      else putchar('0');
   }//ens for
}
int main(){
   int x,z;
   printf ("enter 0x:");
   scanf("%d",&x);
   
   z= putbin(x);
   
   //printf("%d",z);
      
   getch();
   return 0;
}
/*
int main(){
   int array[10];
   int i;
   
   printf ("enter 0x:");
   
   for (i=0;i<11;i++){
      scanf("%d",array[i]);
      /*switch (array[i]){
            case 0:printf ("0000");
            case 1:printf ("0001");
            case 2:printf ("0010");
            case 3:printf ("0011");
            case 4:printf ("0100");
            case 5:printf ("0101");
            case 6:printf ("0101");
            /*case 7:printf ("0111");
            case 8:printf ("0100");
            case 9:printf ("0101");
            case 0:printf ("0000");
            case 0:printf ("0000");
            case 1:printf ("0001");  
            case 1:printf ("0001");
            case 0:printf ("0000");
            case 1:printf ("0001");
      }//end switch 
   }// enf for
   
   printf("%d", array[1]);
   
}*/
