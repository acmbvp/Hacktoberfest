///this code is used to sort 0 1 2 in an array in the ascending order.
#include <iostream>
using namespace std;
void sort012(int arr[], int n)  {  
       
  int i,j,k;
  i=0;
  j=0;
  k=n-1;
  while(i<k)
  {
    if(arr[i]==0)
    {
      arr[i]=arr[i]+arr[j];
      arr[j]=arr[i]-arr[j];
      arr[i]=arr[i]-arr[j];
      i++;
      j++;
     
    }
  else if(arr[i]==2)
    {   
       arr[i]=arr[i]+arr[k];
      arr[k]=arr[i]-arr[k];
      arr[i]=arr[i]-arr[k];
       k--;
    
    }
    else
      i++;  
  }
}

int main() {

	int size_first;

	cin>>size_first;
	int *arr_first=new int[1+size_first];	
	
	for(int i=0;i<size_first;i++)
		cin>>arr_first[i];
	
	sort012(arr_first,size_first);
		
	for(int i=0;i<size_first;i++)
		cout<<arr_first[i]<<" ";	
	return 0;
}
