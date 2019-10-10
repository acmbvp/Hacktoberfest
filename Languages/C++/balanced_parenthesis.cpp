#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(char *a)   //Return True If condition is satisfied
{
    stack<char> s;
    for(int i=0;a[i]!='\0';i++)
    {   char ch = a[i];
        switch(ch)
        {
        case '[':
        case '{':
        case '(': s.push(ch);
                  break;
        case ')': if(!s.empty()&&s.top()=='(')  // Check if stack is not empty and Top symbol is of the same sign
                  {
                    s.pop();
                    break;
                  }
                  else
                    return false;
        case ']': if(!s.empty()&&s.top()=='[')
                  {
                        s.pop();
                        break;
                  }
                  else
                        return false;
        case '}': if(!s.empty()&&s.top()=='{')
                  {
                        s.pop();
                        break;
                  }
                  else
                        return false;
        }
    }
    return s.empty(); //Return True If Empty
}
int main()
{
    char a[] = "{ a + [ b+ (c + d)] + (e + f)}";
    isBalanced(a)? cout<<"Balanced":cout<<"Not Balanced";
    return 0;
}
