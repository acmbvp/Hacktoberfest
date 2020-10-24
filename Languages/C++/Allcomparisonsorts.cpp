
int partition(vector<int>&a, int l,int r)
{
    int pind=l;
    int comp=a[r];
    for(int i=l;i<r;i++)
    {
        if(a[i]<=comp)
        {
            swap(a[i],a[pind]);
            pind++;
        }

    }
    swap(a[r],a[pind]);
    return pind;

}
void quicksort(vector<int>&a, int l,int r)
{
    if(l<r)
    {
        int pivot=partition(a,l,r);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,r);
    }
}
void heapify(vector<int>&a,int index,int n)
{
    int largest=index;
    int l=2*index+1;
    int r=2*index+2;
    if(l<n && a[largest]<a[l])
    {
        largest=l;
    }
    if(r<n && a[largest]<a[r])
    {
        largest=r;
    }
    if(largest!=index)
    { 
        swap(a[index],a[largest]); 
        heapify(a,largest,n);
    }

}
void buildmaxheap(vector<int>&a,int n)
{
    for(int i=n/2 -1; i>=0;i--)
    {
        heapify(a,i,n);
    }
}
void heapsort(vector<int>&a,int n)
{
    buildmaxheap(a,n);
    while(n>0)
    {
       swap(a[0],a[n-1]);
       n=n-1;
       heapify(a,0,n);
    }


}
void bubblesort(vector<int>& a)
{
    bool s;
    for(int i=0;i<a.size();i++)
    {
        s=false;
        for(int j=0;j<a.size()-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                s=true;
                swap(a[j+1],a[j]);
            }

        }
        if(s==false){break;}
    }
}
void insertionsort(vector<int>& a)
{
    for(int i=0;i<a.size();i++)
    {
        int index=a[i];
        int j=i-1;
        while(j>=0 && a[j]>index)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=index;
    }
}
void mergesort(vector<int>& a,int start,int end)
{
    if(start<end)
    {
        int m=start+ (end-start)/2;
        mergesort(a,start,m);
        mergesort(a,m+1,end);
        merge(a,start,m,end);
    }
}
void merge(vector<int>& a,int start,int mid,int end)
{
    vector<int> tmp(end-start+1,0);
    int i=start,j=mid+1;
    int k=0;
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
        {
            tmp[k]=a[i];
            k++;i++;
        }
        else
        {
            tmp[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid)
    {
         tmp[k]=a[i];
         k++;i++;
    }
     while(j<=end)
    {
         tmp[k]=a[j];
         k++;j++;
    }
    for(int p=start;p<=end;p++)
    {
        a[p]=tmp[p-start];
    }
}
void selectionsort(vector<int>&a)
{
    int mini;
    for(int i=0;i<a.size()-1;i++)
    {
        mini=i;
        for(int j=i+1;j<a.size();j++)
        {
            if(a[j]<a[mini])
            {
                mini=j;
            }
        }
        if(mini!=i)
        {
            swap(a[mini],a[i]);
        }
    }
}
vector<int> sortArray(vector<int>& nums) {
    //UNCOMMENT ANY SORTING METHOD
    // quicksort(nums,0,nums.size()-1);
    // bubblesort(nums);
    // insertionsort(nums);
    // mergesort(nums,0,nums.size()-1);
    // selectionsort(nums);
    //heapsort(nums,nums.size());
    return nums;

}
