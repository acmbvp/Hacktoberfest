#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
        int data;
        node *next;
    };

node *top = NULL;
node *maxtop = NULL;

void push(int x)
{
    if(maxtop == NULL)
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = maxtop;
        maxtop = temp;
    }
    else if(maxtop->data < x)
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = maxtop;
        maxtop = temp;
    }
    node *n = (node*)malloc(sizeof(node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop()
{
    if(top != NULL)
    {
        if(maxtop->data == top->data)
            maxtop = maxtop->next;
        top = top->next;
    }
}

void max()
{
    if(maxtop)
        cout<<maxtop->data<<"\n";
}

void printnode()
{
    node *t = top;
    cout<<"Stack : ";
    while(t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    t = maxtop;
    cout<<"\nMaxStack : ";
    while(t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<"\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, N, type, x;
    cin>>N;
    for(i=0; i<N; i++)
    {
        cin>>type;
        if(type == 1)
            cin>>x;
        switch(type)
        {
            case 1: push(x);
                    break;
            case 2: pop();
                    break;
            case 3: max();
                    break;
        }
        //printnode();
    }
    return 0;
}
