#include<iostream.h>
#include<conio.h>

void main()
{
int a,b,c,i,n,x[100],sum=0;
clrscr();
cout<<"Enter the number"<<endl;
cin>>n;
a=0;
b=1;
c=a+b;

	i=0;
      while(c<n)
      {
	c=a+b;
	if(c%2==0)
	{
	x[i]=c;
	i++;
	}
	a=b;
	b=c;

       }

for(int j=0;j<i;j++)
{
sum = sum + x[j];
}
cout<<sum;

getch();
}
