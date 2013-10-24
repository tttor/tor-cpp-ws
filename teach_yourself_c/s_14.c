#include <stdio.h>
#include <conio.h>

int main (void)
{
/*int num;
num=77;
printf("%d is the value of num",num);*/
int x;

for (x=10;x>0;x-=2) printf ("%03d\t",x);
getch();
return 0;
}
