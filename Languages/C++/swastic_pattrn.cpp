#include<iostream>
using namespace std;
int main()
{
    int n,hn;
    cin>>n;
    hn=(n+1)/2;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            if((j==hn)||(i==hn)||((i==1)&&(j>=hn))||((i==n)&&(j<=hn))||(j==1&&i<hn)||(j==n)&&(i>hn))   cout<<"*";     else    cout<<" ";

                j++;

        }
        cout<<endl;
        i++;
    }
    return 0;
}
