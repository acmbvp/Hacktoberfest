/*
Code by Urjita Sharma
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


int rodCut(vector<int> price,int n){

    vector<int>val(n+1,INT_MIN);  //max value of rod for each length.
    val[0]=0; // value of rod of length zero is zero/\.

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            val[i]=max(val[i],price[j]+val[i-j-1]);
        }
    }

    return val[n]; //max value of rod of length n.
}


int main() {
cout<<"Enter length of rod. ";
int n; cin>>n;
cout<<endl;
vector<int> prices(n,0);

for(int i=0;i<n;i++){
    cout<<"Enter price of rod of length "<<i+1;
    int x;
    cin>>x;
    cout<<endl;
    prices[i]=x;
}
cout<<"Maximum value of the rod can be - "<<rodCut(prices,n)<<endl;

}

