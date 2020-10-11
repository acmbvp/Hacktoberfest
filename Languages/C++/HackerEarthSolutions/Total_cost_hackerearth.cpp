#include<bits/stdc++.h>

using namespace std;

int main()
{
  long long int p=0,s=0,t=0,h=0,x=0,sum=0;

  cin>>p>>s>>t>>h>>x;

  while(x--)
  {
    if(s>t)
        sum = sum + p;
    else
        sum = sum + h;

    s--;
  }

  cout<<sum<<endl;

  return 0;
}
