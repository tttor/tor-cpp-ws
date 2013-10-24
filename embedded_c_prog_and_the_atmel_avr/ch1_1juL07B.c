// POINTER TO FUNCTIONS
#include <stdio.h>
#include <conio.h>

void first(void){
   printf (" u run first function\n");
}
void second(void){
   printf (" u run 2nd function\n");
}
void third(void){
   printf (" u run 3rd function\n");
}

// i think below is just an initializing of array of pointer to function


int main (void){
   int funcNum;
   void (*fp) (void);//fp is pointer to functions
   
   void (*taskList[3]) (void) ={
   first,
   second,
   third
   };
      
   printf ("select function ");
   scanf("%d",&funcNum);
   
   if ((funcNum>0) && (funcNum<4)){
   //  fp=taskList[funcNum-1];
     //(*fp)();
     (*taskList[funcNum-1])();
   }//endof IF
   else printf("wah gak bener, keluar dulu baru ngulang!!");
   
   getch();
   return 0;
   
}//endof MAIN

