//Program to check if a entered number is a pallindrome
#include<iosteam>
using namespace std;
int main()
{
cout<<"Enter a number :";
int n;cin>>n;int num=n;
int rem;int reverse{};
while(num>0)
{ 
rem=num%10;
reverse=reverse*10+rem;
num=num/10;
}

if(reverse==n)
{
cout<<"The number is a pallindrome."<<endl;
}else
{
cout<<"The number is not a pallindrome."<<endl;
}
return 0;
}

