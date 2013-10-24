#include <stdio.h>
#include<string.h>
#include<conio.h>

int main(void)
{
   
   char bigstr[1000]="",temp[100]; // anythings that will be incremented must be defined prior the loop 
  

  
    for(;;;) // infinite loop
      {
 
 
        gets (temp);
         
         
//         if (!strcmp(temp,"quit")) break;
         
         strcat (temp,"\n");
         
        
//  ?       if (strlen(bigstr)+strlen(temp)>=1000) break;
       
          strcat(bigstr,temp);
         }
 
     
       
      
   printf (bigstr);
   
   getch();
}
