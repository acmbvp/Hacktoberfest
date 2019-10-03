#include<iostream>
using namespace std;

void swap(int *a,int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}

void heapify(int A[],int len,int i){
  int l=2*i;
  int r=2*i+1;
  int max=i;
  if(l<len && A[l]>A[max]){ max=l;}
  if(r<len && A[r]>A[max]){ max=r;}
  if(max!=i){
    swap(&A[max],&A[i]);
    heapify(A,len,max);
  }
}

void heapSort(int A[],int low,int high){
  int mid=(low+high)/2;
  int n=high-low+1;
  for(int i=mid;i>=0;i--)
    heapify(A,n,i);
  for(int i=high;i>=low;i--){
    swap(&A[0],&A[i]);
    heapify(A,i,0);
  }
}

int main(){
  int n;
  cout<<"Enter the number of array elements \n";
  cin>>n;
  int a[n];
  cout<<"Enter the array elements \n";
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  heapSort(a,0,n-1);
  cout<<"The elements in sorted order are \n";
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
