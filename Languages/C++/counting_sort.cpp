#include<iostream>
using namespace std;
///Counting Sort - Here ,we just mark the frequency of each element in a new array ending at the max element in the array ,then the obtained frequency array can be transformed to a sorted array
int main()
{
    int n ,a[20] , max_no=0;
    cout<<"Enter the range of array"<<endl;
    cin>>n;
    cout<<"Enter the number of elements in the array"<<endl;
    for(int i =0;i<n;i++) /// this for loop for taking input , simultaneously we are finding out the maximum num
    {
        cin>>a[i];
        if(a[i]>max_no)
        {
            max_no = a[i];
        }

    }
    int cnt[100] = {0};
    for(int i =0;i<n;i++) /// we are creating a frequency array by taking counts of each element of the array
    {
        cnt[a[i]] += 1;
    }
    int i =0 , k=0;
    while(i<=max_no) ///just coping the elements onto the unsorted array using frequency array
    {
      while(cnt[i]>0)
      {
         a[k] = i;
         cnt[i] -= 1;
         k++;
      }
      i++;
    }
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
