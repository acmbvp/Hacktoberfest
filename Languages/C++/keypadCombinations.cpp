#include<iostream>
#include<string>
using namespace std;
string helper(int n)
{
  string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  string last=mapping[n];
  return last;
}
void printKeypad(int n,string out="") {
      
  if(n==0)
  {
    cout<<out<<'\n';
    return;
}
  string temp=helper(n%10);
  for(int i=0;i<temp.size();i++)
  {
    printKeypad(n/10,temp[i]+out);
  }

}
int main() {
  int number;
  cin >> number;
  printKeypad(number);
}