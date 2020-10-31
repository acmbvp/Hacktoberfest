#include<conio.h>
#include<iostream.h>

int main()
{
  int arr[10];
  int s=0,j=0;
  clrscr();
  cout<<"enter the elemnets of array";
  for (int i=0;i<10;i++)
  {
    cin>>arr[i];
  s=arr[0];
  for(j=0;j<i;j++)
  {
      if( s<arr[j])
      {
	s=arr[j];
      }
  }
  }
  cout<<" \n high element is "<<s;
getch();
return 0;
}