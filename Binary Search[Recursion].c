#include<stdio.h>

int BS(int a[], int num, int s, int l)
{
	int mid = (s+l)/2;
	while(s <= l)
	{
		if (a[mid] == num)
		{
			return mid;
		}
		else if (a[mid] > num)
		{
			l = mid-1;
			return BS(a, num, s, l);
		}
		else
		{
			s = mid+1;
			return BS(a, num, s, l);
		}
	}
	return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i)          //Insertion Sort
	{
		int x = a[i];
		int hole = i;
		while(hole > 0 && a[hole-1] > x)
		{
			a[hole] = a[hole-1];

			hole--;
		}
		a[hole] = x;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\nWanna Find A Number?: ");
	int num, s, mid, l, f;
	scanf("%d",&num);
	s = 0;
	l = n-1;
	int x = BS(a, num, s, l);
	if (x != -1)
	{
		printf("\nFound At %d",x);
	}
	else
		printf("\nNot Found");

	return 0;
}
