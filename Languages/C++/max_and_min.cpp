// Program to find maximum and minimum of two numbers without using any loops or conditions

#include<bits/stdc++.h>
using namespace std;
int main ()
{
  int first_number , second_number;
  cout<<"Enter first number : ";
  cin>> first_number;
  cout<<"\nEnter second number :";
  cin>> second_number;
  cout<<"\nMaximum of two numbers is : "<<(((first_number + second_number) + abs(first_number - second_number)) / 2);
  cout<<"\nMinimum of two numbers is :"<<(((first_number + second_number) - abs(first_number - second_number)) / 2);
  return 0;
}
