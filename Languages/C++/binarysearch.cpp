#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int x){
    int beg = 0;
    int end = size - 1;
    while(beg <= end){
        int mid = end + (beg - end)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] >= x){
            end = mid-1;
        }
        else{
            beg = mid+1;
        }
    }
    return -1;
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