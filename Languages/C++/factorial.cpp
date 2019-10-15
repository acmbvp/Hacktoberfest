#include <iostream>
using namespace std;
unsigned long long fact(unsigned int n)
{  unsigned long long factorial = 1;
for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
return factorial;
}
int main()
{
    unsigned int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    unsigned long long  ans = fact(n);
    cout << "Factorial of " << n << " = " << ans;    
    return 0;
}
