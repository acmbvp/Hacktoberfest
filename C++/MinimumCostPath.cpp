#include<bits/stdc++.h>
using namespace std;
#define MAX_V 1000000
int arr[51][51];
bool visited[51][51];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

bool isSafe(int x,int y,int n)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}
int minCostPath(int n)
{
    long long int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=1000000;

   // priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,mycompare >pq;
    set<pair<int,pair<int,int> > >pq;
    pq.insert({arr[0][0],{0,0}});
    dp[0][0]=arr[0][0];

    while(!pq.empty())
    {
        pair<int,pair<int,int>>p=*(pq.begin());
        pq.erase(pq.begin());
        int x=p.second.first;
        int y=p.second.second;
        int d=p.first;
        //cout<<x<<"&&"<<y<<endl;
        if(x==n-1 && y==n-1)
        {
            //cout<<x<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<y<<endl;
            return d;
        }

        dp[x][y]=d;
        //cout<<d<<"############"<<endl;
        visited[x][y]=true;

        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            //cout<<x1<<"%%%%"<<y1<<endl;
            //cout<<arr[x1][y1]+d<<"@@@"<<dp[x1][y1]<<endl;
            if(isSafe(x1,y1,n) && !visited[x1][y1] && arr[x1][y1]+d<dp[x1][y1])
            {
                dp[x1][y1]=arr[x1][y1]+d;
                //cout<<dp[x1][y1]<<"$$$$$$$$$$$"<<endl;
                pq.insert({arr[x1][y1]+d,{x1,y1}});
            }
        }
    }
    //return dp[n-1][n-1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];

        memset(visited,0,sizeof(visited));
        cout<<minCostPath(n)<<endl;
    }
    return 0;
}
