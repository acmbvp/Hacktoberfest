#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
int c=0;
int i,j,k=0,s,temp1=0,temp2=0;
char b[100]={'\0'},input[100]="abc def";
for(i=0;input[i]!='\0';i++)
{
c++;
}


for(i=0;i<=c;i++)
{
	if(input[i]==' ' || i==c)
	{       s=k;
		for(j=i-1,k=s;j>=temp1;j--,k++)
		{
			b[k]=input[j];
			temp2++;
		}
		temp1=temp2+1;
		b[k]=' ';
		k++;
	}




}
for(i=0;b[i]!='\0';i++)
{
	input[i]=b[i];
}

printf("%s",input);















getch();
}