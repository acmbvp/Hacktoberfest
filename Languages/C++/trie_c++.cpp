#include <iostream>
#include<unordered_map>
using namespace std;
#define ll long long int

// ---------------Node Class-------------
class Node
{
public:
	char data;
	bool terminal;
	unordered_map<char, Node*> children;

	Node(char data)
	{
		this->data = data;
		this->terminal = false;
	}
};

// ---------------Trie Class--------------
class Trie
{
public:
	Node *root;
	int count;

	Trie()
	{
		this->root = new Node('\0');
		this->count = 0;
	}
	// Add String Function
	void addWord(string str)
	{
		Node *temp = root;
		for(ll i=0;i<str.size();i++)
		{
			char ch = str[i];
			if(temp->children.count(ch) == 1)
			{
				temp = temp->children[ch];
			}
			else
			{
				Node *n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}
	// Search String Function
	bool search(string str)
	{
		Node *temp = root;
		for(ll i=0;i<str.size();i++)
		{
			char ch = str[i];
			if(temp->children.count(ch) == 1)
			{
				temp = temp->children[ch];
			}
			else
			{
				return false;
			}
		}
		return temp->terminal;
	}
};
int main()
{
	Trie t;
	ll n;
	cin >> n;
	while(n--)
	{
		string str;
		cin >> str;
		t.addWord(str);
	}
	ll q;
	cin >> q;
	while(q--)
	{
		string str;
		cin >> str;
		cout << t.search(str) << endl;
	}
    return 0;
}
