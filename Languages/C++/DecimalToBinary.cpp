#include<iostream>
using namespace std;

int main() {
	// Decimal to Binary
	  long long int n,rem;
    long long int ans=0;
    cin>>n; //input number
    long long int temp=n;
    long long int placevalue=1; //placevalue to multiply by power of 10.
    while(temp)
    {
        rem=temp%2;
        ans=ans+placevalue*rem;
        placevalue=placevalue*10;
        temp=temp/2;
    }
    cout<<ans;
}
