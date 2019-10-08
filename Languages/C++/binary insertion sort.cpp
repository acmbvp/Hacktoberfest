#include<bits/stdc++.h>
using namespace std;

int Binary_Search(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low])? (low + 1): low;

	int mid = (low + high)/2;

	if(item == a[mid])
		return mid+1;

	if(item > a[mid])
		return Binary_Search(a, item, mid+1, high);
	return Binary_Search(a, item, low, mid-1);
}

void Insertion_Sort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		loc = Binary_Search(a, selected, 0, j);

		while (j >= loc)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = selected;
	}
}
int main()
{
    int n,i;
    
    cout<<"Enter array size : ";
    cin>>n;
    
    int a[n];
    cout<<"\nEnter array elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];
        
	Insertion_Sort(a, n);
  
	cout<<"\nSorted array : \n";
	for (i = 0; i < n; i++)
	      cout<<a[i]<<" ";


	return 0;
}

