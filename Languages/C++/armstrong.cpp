#include<iostream>
#include<math.h>
using namespace std;
long digits(long n)
{
    long d=10,dig=1;

         while(n>0)
        {
            n/=d;
            d*=10;
            dig++;
        }
    return dig;
}
void armstrong(int n1,int n2)
{
    long n,t1,dig,t;
    for(n=n1;n<=n2;n++)
    {
        long arm=0;

        t1=n;
        dig=digits(n);
        //cout<<"dig"<<dig<<endl;

        while(n>0)
        {
            t=n%10;
            n/=10;
            arm+=pow(t,dig);
            //cout<<"arm "<<arm<<endl;

        }
        n=t1;
        //cout<<"T1 "<<t1<<"arm"<<arm;
        if(arm==t1)
        {
            cout<<t1<<endl;
        }
    }
}
int main()
{
    long a,b;
    cin>>a>>b;
    armstrong(a,b);
    return 0;


}
