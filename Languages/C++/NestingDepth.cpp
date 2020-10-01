#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
/*
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440
*/
int main()
{
	int T,N,element,S,E,end_C,end_J;
	cin >> N;
	vector<vector<int> > Time(N,vector<int> (N,0));
	for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < 2 ; i++)
			{
				cin >> element;
				Time[j][i] = element;
			}
		}
	for (int i = 0; i < N; i++)
	{
		S = Time[i][0];
		E = Time[i][0];
		if(i == 0)
		{
			end_C = E;
			cout<<"C";
		}
		else
		{
			if(S < end_C && S > end_J)
			{
				end_J = E;
				cout<<"J";
				continue;			
			}
			if(S > end_C && S > end_J)
			{
				end_C = E;
				cout<<"C";
				continue;
			}
		}
	}
	return 0;
}
