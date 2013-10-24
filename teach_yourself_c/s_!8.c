/* this is a c program to compute the volume of s cube, made by vektor dewanto*/

#include  <stdio.h>
#include<conio.h>

int main(void)
{
int l,w,t;


printf("enter lenght ");
scanf ("%d",&l);


printf("enter width ");
scanf ("%d",&w);

printf("enter deep  ");
scanf("%d",&t);
printf("volume is %d", l*t*w);


getch();
return 0;
}
