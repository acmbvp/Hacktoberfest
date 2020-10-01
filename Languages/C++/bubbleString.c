#include <stdio.h>
#include<process.h>
#include<conio.h>
/*
This function will read array of size 'size'
*/
void readArray(int x[][40], int size)
	{
	int k; 
	printf("\n Enter %d strings:",size);
	for(k=0; k<size; k++) // repeat for 'size'
		scanf("%s",x[k]); // read string item 
	}
/*
This function will print array x of size 'size'
*/
void printArray(int x[][40], int size)
	{
	int k;
	printf("\n The array items are:\n");
	for(k= 0; k<size; k++) // repeat for all items in array x
		printf("%s  ",x[k]);
	}
/*
This function will sort the array x using bubble sort technique.
*/
void bubbleSort(int x[][40], int size)
	{
	int p, k, temp[40];
	//repaet for size-1 times
	for(p=1; p<size; p++)// number of passes = p-1  i.e. size-1
		{// for all items in array repeat
		for(k=0; k<size-1; k++) // no of comparison = size-1
			{// compare k th item with k +1 th item
			if(strcmp(x[k],x[k+1]) > 0)
				{// swap x[k] and x[k+1]
				strcpy(temp,x[k]);
				strcpy(x[k],x[k+1]);
				strcpy(x[k+1],temp);
				}
			}
		}
	}

int main()
	{
	int x[10];
	printf("\n Read array x:");
	readArray(x,10); // call readArrayFunction
	printf("\n Array x before sort is :");
	printArray(x,10);// Call printArray function 
	bubbleSort(x,10);	// sort the array call bubbleSort function
	printf("\n Array x after sort is :");
	printArray(x,10);
	return 0;
	}
