#include<iostream>
using namespace std;

int catalan(int n){
	
	if(n<=1){
		return 1;
	}
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += catalan(i)*catalan(n-i-1);
	}
	
	return sum;
}


int main(){
for(int i=0;i<=10;i++){
	cout<<catalan(i)<<"  ";
}
	return 0;
}
