#include <stdio.h>
#include <conio.h>

int main (void) {
  char *p,*HOW="it is 10.37p; today monday 19th mar 07--9.05a",*t="stop",str[80];// more efficient to write here
  
 p="vektor dewanto"; // *p point directly to stirng constant or it can be written in above line see HOW...
  
  
  printf (p);
  printf ("\n");
  printf (HOW);
  printf ("\n");
  do{
  printf("write urs here ...?");
  gets(str);
  }while (strcmp(t,str));// take a closer look:: strcmp() will give 0 if they're same, therefore while ... not 0 namely 1 = they're not same the "DO" will work
  
}
