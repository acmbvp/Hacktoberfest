#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        stack<int>st;
        int freq[n];
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[i]>arr[st.top()])
            {
                //cout<<st.top()<<"&&"<<i<<endl;
                freq[st.top()]=i;
                st.pop();
            }

            st.push(i);
        }
        while(!st.empty())
        {
            //cout<<"555"<<endl;
            freq[st.top()]=-1;
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            cout<<abs(freq[i]-i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
