#include <iostream>
using namespace std;
int main()
{

	//Bitwise operators works on bits instead of the numbers. Cannot directly cout them. Store them in int variable first

	int a,b;
	cin >> a >> b;
	int c = a & b; //Bitwise AND operator
	int d = a | b; //Bitwise OR operator
	int e = ~a;    //Bitwise NOT operator
	int f = a << 1; //Bitwise right shift operator (we remove the left most digit and add 0 at the right most part)
	int g = a >> 1; //Bitwise left shift operator (we remove the right most bit and add 0 at the left most part)
	int h = a ^ b;  //Bitwise XOR operator (XOR's on bits)
	cout<<c<<endl;
  cout<<d<<endl;
  cout<<e<<endl;
  cout<<f<<endl;
  cout<<g<<endl;
  cout<<h<<endl;
}
