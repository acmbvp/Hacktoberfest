#include<iostream>
#include<conio.h>
using namespace std;

int main()
{   int n;
	int a[5]; int ctr=0;
	cout<<"Enter the size of the array:";
	cin>>n;
	for(int i=0;i<n;i++)
	{   cout<<"Enter the value:";
		cin>>a[i];
	}
		for(int i=0;i<n;i++)
	{   cout<<"Value are:"<<a[i]<<"\n";
	
	}
int i =1;
  while (i<n)
  {
  	for(int j=i;j<n;j++)
  	{
  		a[j]=a[j+1];
	  }
	  n--;
	  i++;
	  
  }
    for(int i=0;i<n;i++)
	{
		cout<<"Final Value are:"<<a[i]<<"\n";
	}
getch();
return 0;
}
