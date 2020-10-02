#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int counter(int arr[], int n){
	sort(arr,arr+n);
	int count = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == arr[i+1]){
			count++;
		}
		if(count > n/3){
			cout<<arr[i]<<" ";
			count = 0;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	counter(arr,n);
}