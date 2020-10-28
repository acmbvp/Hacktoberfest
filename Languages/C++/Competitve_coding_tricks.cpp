#include <bits/stdc++.h>  
using namespace std;
#define deb(x) cout << #x << " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++);
#define Fo(i,k,n) for(i=k;i<n;i++);

template <typename... T>
void read(T&... args){
    ((cin >> args), ...);
}

template <typename... T>
void write(T&&... args){  // && is rvalue reference read about it we can also remove && and just pass T... args
    ((cout << args), ...);
}

int main(){

    int x(100),y(200);
    //cout << x << end << y << endl;
    deb(x);
    deb(y);
    int z, zz;
    //cin >> x >> y >> z >> zz;
    read(x,y,z,zz);
    write(x,y,z,zz);
    int i,n;
    cin >> n;
    vector<int> arr(n,0);
    fo(i,n)
        cin >> arr[i];
    
    fo(i,n)
        cout << arr[i];

}
