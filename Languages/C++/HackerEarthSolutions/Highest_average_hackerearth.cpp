#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,q,k,x,j,length=0;
    double avg;
    vector<long long int> v,t;

    v.push_back(0);

    cin>>n;

    for(i=1;i<=n;i++)
    {
       cin>>x;
       v.push_back(x);
    }

    sort(v.begin(),v.end());

    x=0;
    t.push_back(0);

    for(i=1;i<=n;i++)
    {

       x = x + v[i];
       t.push_back(x);
    }

    cin>>q;

    while(q--)
    {
        cin>>k;
        length=0;

        for(i=1;i<=n;i++)
        {
              avg = t[i];
              avg = (avg*1.0)/(i);

              if(avg < k)
                length++;
              else
                break;

        }

        cout<<length<<endl;
    }

    return 0;
}
