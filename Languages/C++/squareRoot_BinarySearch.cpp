#include<iostream>
using namespace std;
/// Doing binary search to find out the square root of a number
float sqrtRoot(int num , int p)
{
    int s=0, e=num , mid; /// start and end for every iteration
    float ans;
    while(s<=e)
    {
        mid = (s+e)/2; /// calculate mid for each iteration
        if(mid*mid == num)
          {
              ans = mid;
              break;
          }
        if(mid*mid < num)
        {
            s = mid +1;
            ans = mid;
        }
        else
        {
            e = mid -1;
        }

    }
    float inc = 0.1;
    for(int i =0;i<p;i++) /// loop for precision
    {
        while(ans*ans <=num)
        {
            ans += inc;
        }
        ans = ans - inc;
        inc = inc/10;
    }
    return ans;
}
int main()
{
    int num , prec;
    cout<<"Please!! Enter the number along with precision"<<endl;
    cin>>num>>prec;
    cout<<"Square Root of "<<num<<" is "<<sqrtRoot(num,prec) ;
    return 0;
}

