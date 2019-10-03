//This code is used to find out the no. of balanced Binary Trees  using DP
#include <iostream> 
#include <cmath>
using namespace std;

int balancedBTs(int h) {
  
    int *output = new int[h + 1];

    int mod = 1000000000 + 7;
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i <= h; i++) {
    
        int x = output[i-1];
        int y = output[i-2];

        int a = (1l * x * x) % mod;
        int b = (1l * 2 * x * y) % mod;
        output[i] = (a + b) % mod;
    } 

    return output[h];
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}