// Sum Of natural Numbers
#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter number for sum: ";
	cin>>num;

	if(num<0){
		cout<<"Invalid";
	}
	else{
		cout<<num*(num+1)/2;
	}
}