#include<iostream>
using namespace std;
void SSort(int A[],int n)
{       for (int i=1;i<n-1;i++)
	{	int small=i;
		int j;
		for ( j=i+1;j<n;j++)
		      if(A[small]>A[j])
				small=j;
		if (small!=i)
		{      int t=A[small];
		       A[small]=A[j];
		       A[j]=t;
		}
	}
	for (int k=0;k<n;k++)
		cout<<A[k]<<",";
}
int main(){
	int A[]={10,5,2,1,4,11};
	SSort(A,6);
	return 0;
}
