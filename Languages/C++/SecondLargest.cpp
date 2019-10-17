#include <iostream>
using namespace std;

int main ()
{
int a[100],s,i;
cout<<"Enter the size :";
cin>>s;

cout<<endl<<"Enter the elements :\n";
for(i=0;i<s;i++)
cin>>a[i];


int maximum=0;
int secondmax=0;

for(int i=0;i<s;i++)
{
if (a[i]>maximum)
maximum = a[i];
}
for(int i=0;i<s;i++)
{
if (a[i]>secondmax && a[i]!=maximum)
{
secondmax=a[i];
}

}
cout << "The second max of the array is :" <<secondmax<< endl;

return 0;
}
