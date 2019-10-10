#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
int ana(string a,string b){
    int cnt[26]={0};
    int sum=0;
    for(int i=0;i<a.length()||i<b.length();i++){
        cnt[a[i]-'a']++;
        cnt[b[i]-'a']--;
    }
    for(int i=0;i<26;i++)   sum+=abs(cnt[i]);
    return sum;
}
int main()
{
    int n;  cin>>n;
    for(int i=0;i<n;i++){
        string a, b;cin>>a>>b;
        cout<<ana(a,b)<<endl;
    }

    return 0;
}
