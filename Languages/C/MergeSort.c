#include <stdio.h>
#include <stdlib.h>

int part(int a[],int l,int r)
{
    int p,i,j,temp;
    p=a[l];
    i=l;
    j=r+1;
    do{
        do{
            i=i+1;
        }while(p>a[i] && i<=r);
        do{
            j=j-1;
        }while(p<a[j]);
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    }while(i<j);
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;
    return j;
}

void quick(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=part(a,l,r);
        quick(a,l,s-1);
        quick(a,s+1,r);
    }
}

int main()
{
    int i,n,a[20];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The elements are\n");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    quick(a,0,n-1);
    printf("Elements after sorting\n");
    for(i=0;i<n;i++)
        printf("%d   ",a[i]);
    return 0;
}

