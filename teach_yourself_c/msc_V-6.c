#include <stdio.h>
#include <conio.h>
#include <string.h>

int main (void) {
   char eng [][2][100]={ // imagine #1 for rows, #2 for columns, #3 for letter in words
   "Unerring", "jernih",
"Tactful", "bijaksana",
"Concise" , "siingkt",""};


char input[100];
int i;

printf ("english  ");
gets (input);

i=0;
while (strcmp (eng[i][0],"")){
   if (!strcmp(input,eng[i][0])){
      printf ("= %s",eng [i][1]);
      break;
      }
   i++;
   }
getch();
}

