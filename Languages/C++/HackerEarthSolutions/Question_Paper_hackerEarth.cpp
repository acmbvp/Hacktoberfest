#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t,n,b,a,max_pos,max_neg,pos,cont;

    cin>>t;

    while(t--)
    {
        max_pos = 0;
        max_neg = 0;
        pos=0;

       cin>>n>>a>>b;

       max_pos = a * n;
       max_neg = b * n;

       cont=0;
       if(a>0)
       {
         cont++;
         a=a-b;
       }

       pos = cont*n;

       if(b>)


    }
  return 0;
}
