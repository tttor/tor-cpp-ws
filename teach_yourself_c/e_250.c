#include <stdio.h>
#include <conio.h>

int main (void){
    char str[80];
    /*
    printf ("enter a string");
    scanf("%s",str);
    printf(str);
    */
    
    /*
    printf ("enter  letters, anything else to stop\n");
    scanf ("%[a-zA-Z]",str);// only the letter in this range will be read: 12132 not be read
    printf (str);
    */
    
    printf ("enter  letters containing a spaces, anything else to stop\n");
    scanf ("%[a-zA-Z ]",str);// pay attention to the "SPACE" in the argument, it allowa u put a space characteter and it will be read
    printf (str);
    
    getch();
    return 0;
}
