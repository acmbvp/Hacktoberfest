#include <iostream>
using namespace std;
int staircase(int n){
   
  int x=0;
   if(n<=1)
     return 1;  
  if(n==2)
    return 2;
     
  for(int i=1;i<=3;i++)
  {
      x+=staircase(n-i);
  }
  
      return x;
    
}
int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
