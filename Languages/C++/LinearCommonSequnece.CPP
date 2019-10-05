#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{
	clrscr();
	char x[10],y[10],v[10][10];
	int a,b,c,d,e,f,g,h,r,z[10][10];
	cin>>x>>y;
	a=strlen(x);
	b=strlen(y);
	for(c=0;c<=b;c++)
	{
		z[0][c]=0;
		v[0][c]='-';
	}
	for(r=0;r<=a;r++)
	{
		z[r][0]=0;
		v[r][0]='-';
	}
	for(r=1;r<=a;r++)
	{
		for(c=1;c<=b;c++)
		{
			if(x[r-1]==y[c-1])
			{
				z[r][c]=z[r-1][c-1] +1;
				v[r][c]='s';
			}
			else if(z[r-1][c]>=z[r][c-1])
			{
				z[r][c]=z[r-1][c];
				v[r][c]='t';
			}
			else
			{
				z[r][c]=z[r][c-1];
				v[r][c]='l';
			}
		}
	}
	for(r=0;r<=a;r++)
	{
		for(c=0;c<=b;c++)
			cout<<z[r][c]<<"\t";
		cout<<endl;
	}
	 cout<<endl;
	for(r=0;r<=a;r++)
	{
		for(c=0;c<=b;c++)
			cout<<v[r][c]<<"\t";
		cout<<endl;
	}
	char str[10];
	r=a;
	c=b;
	d=0;
	while(r>0 && c>0)
	{
		switch(v[r][c])
		{
			case 't':r--;break;
			case 'l':c--;break;
			case 's':str[d]=y[c-1];d++;r--;c--;
		}
	}
	strrev(str);
	cout<<endl;
	cout<<z[a][b];
	cout<<endl<<str;
	getch();
}