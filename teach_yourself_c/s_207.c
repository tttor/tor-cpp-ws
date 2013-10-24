#include <stdio.h>
#include <conio.h>
#include <string.h>

void recurse (int i);

int main (void){
    recurse (0);
    
    getch();
    return 0;
}

void recurse (int i){
    if (i<111) {
        //printf ("%d ",i);
        recurse (i+1);//calls itself
        printf ("\n");
        
        printf ("%d ",i);        
    }
}
