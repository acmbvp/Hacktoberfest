#include<iostream>
using namespace std;

int main() {
	// Reverse the given number
    int n,reverse=0;
    cin>>n;
    while(n)
    {
        reverse=reverse*10+(n%10);
        n=n/10;
    }
	cout<<reverse;
}
