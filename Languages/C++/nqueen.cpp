#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int> > > results;

int isSafe(vector<vector<int> > v,int row,int col){
    int n=v.size();
    for(int i=0;i<col;i++){
        if(v[row][i]) return 0;
    } // map< int, int> row
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(v[i][j]) return 0; // map <int, int> 
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--){
        if(v[i][j]) return 0; // map<int, int> 
    }
    return 1;
}

void backtrack(vector<vector<int> > &v,int col,int n){
    if(col==n){
        results.push_back(v);
        return;
    }
    for(int i=0;i<n;i++){
        int row=i;
        if(isSafe(v,row,col) == 1){
            v[row][col]=1;
            backtrack(v,col+1,n);
            v[row][col]=0;
        }
    }   
}

int main(){
    int n;
    cout << "Input n : length of matrix ";
    cin>>n;
    cout << endl;
    vector<vector<int> > v(n,vector<int>(n,0));
    backtrack(v,0,n);
    for(auto v : results){
        for(auto x:v){
            for(auto y:x) cout<<y<<" ";
            cout<<endl;
        }
        cout<<"--------------"<<endl;
    }
}
