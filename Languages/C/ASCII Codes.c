#include<stdio.h>
#include<conio.h>

int main()
{
	int i;
	printf("Characters and their ASCII codes: \n");
	for(i=1; i<256; i++)
	{
		printf("%d : ", i);
		(char) i;
		printf("%c \n", i);
	}
	
	getch();
	return 0;
}
