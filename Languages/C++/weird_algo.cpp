#include <iostream>

using namespace std;

int main(void)
{   
    int n;

    cout<<"Enter the Number : ";
    cin>>n;
    cout<<n<<" ";
    while(n!=1)
    {
        if ( n % 2 == 0)
        {
            n /= 2;
            cout<<n<<" ";
        }
        else
        {
            n *= 3 + 1;
            cout<<n<<" ";
        }
        
    }

return 0;
    
}