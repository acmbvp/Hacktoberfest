#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 50

int stack[MAX];
int top=-1;

void push(int val);
int pop();
int evaluatepostfix();

char postfix[MAX];

int main()
{
	int ans;
	printf("Enter the postfix expression:");
	gets(postfix);

	ans=evaluatepostfix();
	printf("\nThe value of the expression is %d",ans);

	return 0;
}

void push(int val)
{
	if(top==MAX-1)
	{
		printf("\nStack is full.");
	}
	else
	{
		top++;
		stack[top]=val;
	}
}

int pop()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return stack[top--];
	}
}

int evaluatepostfix()
{
	int i=0;
	int n1,n2;
	int val;
	while(postfix[i]!='\0')
	{
		if(isalpha(postfix[i]))
		{
			printf("Enter the value of %c:",postfix[i]);
			scanf("%d",&n1);
			push(n1);
		}
		else
		{
			n2=pop();
			n1=pop();
			switch(postfix[i])
			{
				case '+':
					val=n1+n2;
					break;
				case '-':
					val=n1-n2;
					break;
				case '*':
					val=n1*n2;
					break;
				case '%':
					val=n1%n2;

			}
			push(val);
		}
		i++;	

	}
	return pop();

}

