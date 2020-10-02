#include<iostream>
#include<string>
using namespace std;

int newly_added(string a,string b){
	int s1 = a.length();
	int s2 = b.length();


	// if(s1 == s2){
	// 	cout<<"No element added";
	// }

	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			if(a[i] == b[j]){
				b[j] = '*';
				break;
			}
		}
	}

	for(int i=0;i<s2;i++){
		if(b[i] != '*')
			cout<<b[i];
	}
}

int main(){
	string s,t;
	cin>>s>>t;
	newly_added(s,t);
}