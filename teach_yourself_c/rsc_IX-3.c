                        //PRIME NUMBER//
#include <stdio.h>
#include <conio.h>

int isprime(int i);//this s prototype

int main(void){
    int i,count;
    
    count=0;
    for (i=2;i<500;i++)
        if (isprime(i)){
                printf ("%5d",i);//number before d used to defined the space between columns , it's a width specifier
                count++;
                if (count==7) {
                                printf ("\a\n");
                                count =0;
                }
        }
        getch();
}

int isprime(int i){
    int j;
    
    for (j=2;j<=(i/2);j++) if (!(i%j)) return 0;// this is formula for finding prime number ""IMPORTANT""!!
    return 1;
}
    



