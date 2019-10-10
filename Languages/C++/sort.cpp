
#include<bits/stdc++.h>
using namespace std;
void swap_(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
int partition_(int arr[],int start,int last)
{
    int pivot=arr[1];
    int i=0;
    for(int j=i+1;j<last;j++)
    {
        if(arr[j]<=pivot)
        {
            i=i+1;
            swap_(&arr[i],&arr[j]);
        }
    }
        swap_(&arr[i],&arr[pivot]);
        return i;
    }
int quicksort(int arr[],int start,int last)
{

    if(start==last)
        return arr[start];
    else
    {
        int piv=partition_(arr,start,last);
        quicksort(arr,start,piv-1);
        quicksort(arr,piv+1,last);

    }
}
int main()
{
    int arr[5]={12,1,34,467,8};
    int n=sizeof(arr)/sizeof(arr)[0];
    quicksort(arr,0,n-1);
    cout<<"The sorted Array is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
