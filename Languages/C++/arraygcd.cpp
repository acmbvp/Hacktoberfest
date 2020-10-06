#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
if(a>b)
swap(a,b);
if(a==0)
return b;
else
return gcd(b%a,b);
}
int gcdarray(int arr[],int n)
{
int result=arr[0];
for(int i=1;i<n;i++)
{
     result=gcd(result,arr[i]);
     if(result==1)
     return result;
}
return result;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<gcdarray(arr,n);
    }
