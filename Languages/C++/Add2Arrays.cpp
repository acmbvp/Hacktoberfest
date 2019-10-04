//Program to add 2 arrays

#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int n1,arr1[100000],n2,arr2[100000],i,cnt=0,n,x;
    float number=0;
    cout<<"Enter the size of the first array";
    cin>>n1;
    cout<<"Enter the size of the second array";
    cin>>n2;
    if(n1>n2)
        x=n1+1;              //x is the size of the new array(1 greater than the bigger size)
    else
        x=n2+1;
    int arr3[x];
    for(i=0;i<n1;i++)
        cin>>arr1[i];
    for(i=0;i<n2;i++)
        cin>>arr2[i];
    for(i=0;i<n1;i++)
        number+=arr1[i]*pow(10,n1-1-i);   //143=100+40+3
    for(i=0;i<n2;i++)
        number+=arr2[i]*pow(10,n2-1-i);  //adding both no.s
    n=number;
    for(i=0;n!=0;i++)
        {
            arr3[i]=n%10;
            n/=10;              //for converting no. into array
            cnt++;
        }
    if(cnt<x)
      {
          arr3[cnt]=0;
          for(i=cnt;i>=0;i--)  //for displaying array with a zero
            cout<<arr3[i];
      }
    else
      {
          for(i=cnt-1;i>=0;i--)
            cout<<arr3[i];
      }
    return 0;
}
