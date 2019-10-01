#include<iostream.h>
#include<conio.h>
void main()
 {
  clrscr();
  int m,n,flag,i,j;

  cout<<"Enter the lower limit for prime numbers:\t";
  cin>>n;
  cout<<"Enter the upper limit for prime numbers:\t";
  cin>>m;
  cout<<"Prime numbers between the range:\n";

  for (i=n;i<=m;i++)
   {
    flag=1;
    for (j=2;j<=i/2;j++)
     {
      if (i%j==0)
       {
	flag=0;
	break;
       }
     }
    if (flag==1)
     cout<<i<<" ";
   }

  getch();
 }
