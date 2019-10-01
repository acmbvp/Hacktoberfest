//return greatest integer value of input user.

#include <iostream>

using namespace std ;

int main()
{
	float var;
	cin>>var ;
	float decimal_part = var - int(var);
	if(decimal_part == 0.000)
		cout<<"Greatest integer value of "<<var<<" is "<<var<<endl;
	else 
		cout<<"Greatest integer value of "<<var<<" is "<<((int)var +1)<<endl;
} 
