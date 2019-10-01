//Linear search in given array .
//return index of searching element if it is present .


#include <iostream>
using namespace std ;

int main()
{
	int n;
	cout<<"Number of Elements"<<endl;
	cin>>n;
	int A[n+1];int index_key = -1;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];

	}
	cout<<"searching Element"<<endl;
	int search_Key;
	cin>>search_Key;
	for(int i=0;i<n;i++)
	{
		if(A[i] == search_Key)
		{
			index_key = i;
		}
	}
	if(index_key != -1)
	{
		cout<<"Element is present at index "<<index_key<<endl;
	}
	else
		cout<<"Element is not present in given array ."<<endl ;
}