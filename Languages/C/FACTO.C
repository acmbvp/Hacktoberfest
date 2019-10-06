//Factorial of a Number

#include<conio.h>
#include<stdio.h>

void main()
{
 int n,m=0, fac=1;
 clrscr();

 printf("Enter number: ");
 scanf("%d", &n);
 m=n;
 while(n)

 {
  fac =  fac * n;
  n-=1;
  }
 printf("Factorial of %d is %d",m,fac);
 getch();
}