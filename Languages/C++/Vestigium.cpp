#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int T,N,element;
	cin >> T;
	int k,r,c, prev;
	for(int a = 0; a < T; a++)
	{
		cin >> N;
		k = c = r = 0;
		vector<vector<int> > matrix(N,vector<int> (N,0));
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N ; i++)
			{
				cin >> element;
				matrix[j][i] = element;
				if (i == j)
				{
					k += matrix[j][i];
				}
			}
		}
		for(int i = 0; i < N ; i++)
		{
			//ROWS
			for(int j = 0; j < N; j++)
			{
				prev = r;
				for(int k = j+1; k < N; k++)
				{
					if( matrix[i][k] == matrix[i][j])
					{
						r++;
						break;
					}
				}
				if( prev != r)
					break;	
				
			}
			
			//COLUMNS
			for(int j = 0; j < N; j++)
			{
				prev = c;
				for(int k = j+1; k < N; k++)
				{
					if( matrix[k][i] == matrix[j][i])
					{
						c++;
						break;
					}
				}
				if( prev != c)
					break;	
				
			}
		} 
		matrix.clear();
		cout << "case #" << T << ": " << k << " " << r << " " << c << " " <<endl;
	}
	return 0;
}
