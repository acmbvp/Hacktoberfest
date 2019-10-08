#include<stdio.h>
int main()
{
	int n,i,j,C;
	printf("Enter number of lines :");
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
{
	 C = 1;
	for ( j = 1; j<= i; j++)
	{
	printf("%d ", C);
	C = C * (i - j) / j;
	}
	printf("\n");
}
    return 0;
}

