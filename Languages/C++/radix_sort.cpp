#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2){
	return p1.second > p2.second;
}
void fun(int a[], int n){
	vector<pair<int, int>> v;
	int no[n];
	for(int i = 0; i < n; i++){
		no[i] = a[i];
	}
	int j = 0;
	while(j < 10){
		v.clear();
		for(int i = 0; i < n; i++){
			if(no[i] > 10){
				v.push_back({no[i] % 10, a[i]});
				no[i] = no[i] / 10;
			}
			else
			{
				v.push_back({no[i], a[i]});
			}
		}
		j++;
		sort(v.begin(), v.end(), compare);
	}
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << v[i].second << endl;
	}
}
int main(){
	int a[] = { 100, 180, 260, 310, 40, 535, 695 }; 
    int n = sizeof(a) / sizeof(a[0]); 
	
	fun(a, n);
	return 0;
}