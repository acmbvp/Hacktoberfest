#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

int addNumber(int x, int y);
int subtNumber(int x, int y);
int prodNumber(int x, int y);
int divNumber(int x, int y);

int main()
{ int a, b, choice, answ;
    cout<<"Enter the first number: ";
    cin>>a;

    cout<<"Enter the second number: ";
    cin>>b;

    cout<<"Enter your choice out of 1/2/3/4 where "<<endl<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division"<<endl<<"Your choice is"<<endl ;
    cin>>choice;

    cout<<"***************************************************************"<<endl;
    switch(choice)
    {
    case 1: answ = addNumber(a,b);
            cout<<"The sum of the two numbers is: "<<answ;
            break;
    case 2: answ = subtNumber(a,b);
            cout<<"The difference of the two numbers is: "<<answ;
            break;
    case 3: answ = prodNumber(a,b);
            cout<<"The product of the two numbers is: "<<answ;
            break;
    case 4: answ = divNumber(a,b);
            cout<<"The quotient of the two numbers is: "<<answ;
            break;
    default: cout<<"Invalid Entry";
    }
    return 0;
}

    int addNumber(int x, int y)
      {
          int ans;
          ans = x+y;
          return ans;
      }

    int subtNumber(int x, int y)
      {
          int ans;
          ans = x-y;
          return ans;
      }

    int prodNumber(int x, int y)
      {
          int ans;
          ans = x*y;
          return ans;
      }

    int divNumber(int x, int y)
      {
          int ans;
          ans = x/y;
          return ans;
      }
