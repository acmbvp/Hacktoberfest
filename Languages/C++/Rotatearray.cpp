#include<bits/stdc++.h>
using namespace std;
void rotateArr( int *, int , int);
int main()
{
    int t;
    cin>>t;
    while( t > 0){
        int n,d;
        cin>>n>>d;
        int a[n];
        for(int i = 0 ; i < n ; i++)
            cin>>a[i];
        rotateArr(a,n,d);
    t--;
    }
return 0;
}
void rotateArr(int *a, int n , int d){
    int tempArr[d];
    for( int i = 0; i < d; i++){
        tempArr[i] = a[i];
    }
    for(int i = 0; i < n-d ; i++){
        a[i] = a[i+d];
    }
    for(int i = 0; i < d; i++){
        a[n-d+i] = tempArr[i];
    }
    for( int i = 0; i < n ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
