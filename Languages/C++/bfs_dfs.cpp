/*Hamza Baran Genç
  150150128
  Algo II project 1
*/
#include<iostream>
#include<list>
#include<map>
#include <cmath>
#include <stack>
#include <ctime>
#include<queue>

using namespace std;


class Node{
public:
	bool Farmer, Fox, Rabbit, Carrot;
	int number;
	void Display(){
		if (Farmer == 1)
			cout << "Farmer ";
		if (Fox == 1)
			cout << "Fox ";
		if (Rabbit == 1)
			cout << "Rabbit ";
		if (Carrot == 1)
			cout << "Carrot";
		cout << "||";
		if (Farmer == 0)
			cout << "Farmer ";
		if (Fox == 0)
			cout << "Fox ";
		if (Rabbit == 0)
			cout << "Rabbit ";
		if (Carrot == 0)
			cout << "Carrot ";
		cout << endl;
	}
};

class Tree{
public:
	Node * next;
};

class Graph
{
public:
	Node * arr[16];
	bool adj[16][16];
	Graph(){
		for (int a = 0; a < 16; a++)
		{
			for (int q = 0; q < 16; q++)
			{
				adj[q][a] = 0;
				adj[a][q] = 0;
			}
		}
		int counter = 0;
		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				for (int z = 0; z < 2; z++)
				{
					for (int k = 0; k < 2; k++)
					{
						Node *temp = new Node();
						if (k == 0)
							temp->Carrot = true;
						else
							temp->Carrot = false;
						if (z == 0)
							temp->Rabbit = true;
						else
							temp->Rabbit = false;
						if (y == 0)
							temp->Fox = true;
						else
							temp->Fox = false;
						if (x == 0)
							temp->Farmer = true;
						else
							temp->Farmer = false;
						arr[counter] = temp;
						arr[counter]->number = counter;
						counter++;
					}
				}
			}
		}
	}
	void createAdjList(){
		for (int x = 0; x < 16; x++)
		{
	

			for (int y = 0; y < 16; y++)
			{
				if (valid(x) && valid(y))
				{

					if (((arr[x]->Farmer + arr[y]->Farmer) == 1) && (y != x))
					{


						int changeInCarr = abs(arr[x]->Carrot - arr[y]->Carrot);
						int changeInFox = abs(arr[x]->Fox - arr[y]->Fox);
						int changeInRab = abs(arr[x]->Rabbit - arr[y]->Rabbit);
						int temp = changeInCarr + changeInFox + changeInRab;
						if (temp == 1)
						{
							if (changeInCarr == 1)
							{
								if (arr[y]->Farmer == arr[y]->Carrot){
									adj[x][y] = 1;
									adj[y][x] = 1;

								}
							}
							if (changeInFox == 1)
							{
								if (arr[y]->Farmer == arr[y]->Fox)
								{
									adj[x][y] = 1;
									adj[y][x] = 1;
								}

							}
							if (changeInRab == 1)
							{
								if (arr[y]->Farmer == arr[y]->Rabbit)
								{
									adj[x][y] = 1;
									adj[y][x] = 1;
								}

							}

						}

						if (temp == 0)
						{
							adj[x][y] = 1;
							adj[y][x] = 1;
						}

					}
				}
			}
		}
	}
	void bfs(){
		int biggest = 0;
		clock_t begin = clock();
		int visitednodecounter = 0;


		queue<int> que;
		bool visited[16];
		for (int x = 0; x < 16; x++)
			visited[x] = false;

		que.push(0);
		visited[0] = true;

		while (!que.empty())
		{
			int temp = que.front();
			que.pop();
			arr[temp]->Display();
			for (int x = 0; x < 16; x++)
			{
				if (isConnected(x, temp) && !visited[x])
				{
					que.push(x);
					visited[x] = true;
					if (que.size() > biggest)
						biggest = que.size();
				}
			}

		}
		for (int x = 0; x < 16; x++)
		{
			if (visited[x] == true)
				visitednodecounter++;

		}
		clock_t end = clock();
		double elapsedtime = double(end - begin) / CLOCKS_PER_SEC;

		cout << "elapsed time: " << elapsedtime << endl;
		cout << "Nodes visited : " << visitednodecounter << endl;
		cout << "Biggest queue size : " << biggest << endl;
	}
	void dfs()
	{
		int biggest = 0;
		int visitednodecounter = 0;
		clock_t begin = clock();
		stack<int> stack;
		biggest = stack.size();
		bool visited[16];
		for (int i = 0; i < 16; i++)
			visited[i] = false;

		visited[0] = true;
		stack.push(0);
		cout << "DFS starting at: " << endl;

		while (stack.empty() != 1)
		{

			int x = stack.top();
			arr[x]->Display();
			stack.pop();
			if (x == 15)
				break;
			for (int i = 15; i >= 0; i--)
			{
				if (isConnected(x, i) && !visited[i])
				{
					stack.push(i);
					visited[i] = true;
				}
				if (stack.size() > biggest)
					biggest = stack.size();
			}
		}
		for (int x = 0; x < 16; x++)
		{
			if (visited[x] == true)
				visitednodecounter++;

		}
		clock_t end = clock();
		double elapsedtime = double(end - begin) / CLOCKS_PER_SEC;
		cout << "elapsed time: " << elapsedtime << endl;
		cout << "Nodes visited : " << visitednodecounter << endl;
		cout << "Biggest stack size : " << biggest <<endl;
			

	}
	bool isConnected(int a, int b)
	{
		
		return adj[a][b];
	}

	bool valid(int x){
		if (arr[x]->Rabbit == 0 && arr[x]->Carrot == 0 && arr[x]->Fox == 1 && arr[x]->Farmer == 1)
			return false;
		else if (arr[x]->Rabbit == 1 && arr[x]->Carrot == 1 && arr[x]->Fox == 0 && arr[x]->Farmer == 0)
			return false;
		else if(arr[x]->Rabbit == 1 && arr[x]->Carrot == 0 && arr[x]->Fox == 1 && arr[x]->Farmer == 0)
			return false;
		else if(arr[x]->Rabbit == 0 && arr[x]->Carrot == 1 && arr[x]->Fox == 0 && arr[x]->Farmer == 1)
			return false;
		else if(arr[x]->Rabbit == 0 && arr[x]->Carrot == 0 && arr[x]->Fox == 0 && arr[x]->Farmer == 1)
			return false;
		else if(arr[x]->Rabbit == 1 && arr[x]->Carrot == 1 && arr[x]->Fox == 1 && arr[x]->Farmer == 0)
			return false;
		else
			return true;
	}
};



int main(int argc, char * argv[]){

	Graph temp;
	temp.createAdjList();
	string arg = argv[1];
	try{
		if (arg == "dfs")
			temp.dfs();
		if (arg == "bfs")
			temp.bfs();
	}
	catch(exception x){
		cout << "Whooops" << endl;
	}

}
