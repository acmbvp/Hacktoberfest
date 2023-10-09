#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int x){
    int beg = 0;
    int end = size - 1;
   if(beg>end)
    return false;

    int mid = beg+ (end-beg)/2;

    if (arr[mid] == x)
    return true;

    if(arr[mid]>x){
        binarySearch(arr, beg, mid-1, x);
    }
    else{
        binarySearch(arr, mid+1, end, x);
    }
}

int main(){

    int size;
    cout<<"Enter the Size of List: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the List(in sorted manner): ";
    cout<<endl;
    for (int  i = 0; i < size; i++){
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the number to be searched: ";
    cin>>x;

    int pos = binarySearch(arr, size, x);
    if(pos == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at: "<< pos+1;
    }

    return 0;       
}
