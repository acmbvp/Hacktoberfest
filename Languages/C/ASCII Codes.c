#include<stdio.h>

void main()
{
	int i;
	printf("Characters and their ASCII codes: \n");
	for(i=1; i<256; i++)
	{
		printf("%d : ", i);
		printf("%c \n", (char)i);
	}
	
}
