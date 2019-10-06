void main()
{
	clrscr();

char a[100];
int temp2=0,temp1=0,c=0;
scanf("%s",&a);
 for(int i=0;a[i]!=0;i++)
 {
 	c++;
 }

 for(i=0;i<c;i++)
 {
 	if(a[i]==" ")
 	{
 		
 		for(int j=i;j>temp1;j--)
 		{
 			printf("%c",a[i]);
 		}
 		temp1++;

 	}



 }
 getch();
}
