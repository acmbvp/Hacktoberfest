#include<iostream>
 
using namespace std;
void insort(int a[],int n)
{
  int i,j;
  for(i=1;i<=n-1;i++)
    {
        int temp=a[i];
        j=i-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int n,i,a[30];
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"\nEnter the elements\n"; 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    intsort(a,n);
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 
    return 0;
}
