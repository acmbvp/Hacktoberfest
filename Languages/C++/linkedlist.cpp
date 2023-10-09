#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *head;

void create(int v)
{
    struct node *tmp, *q;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = v;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = tmp;
    }
}

int display()
{
    struct node *q;
    if (head == NULL)
    {
        cout << "List is empty"<<endl;
        return 0;
    }
    else
    {
        q = head;
        cout << "The list is:- ";
        while (q != NULL)
        {
            cout << q->data << " ";
            q = q->next;
        }
    }
    cout << endl;
}

void add_start(int d)
{
    struct node *tmp;
    tmp->data = d;
    tmp->next = head;
    head = tmp;
}

void add_between(int b, int pos)
{
    int i;
    struct node *tmp, *q;
    q = head;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = b;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
    }
    tmp->next = q->next;
    q->next = tmp;
}

int del(int e)
{
    struct node *tmp, *q;
    if (head->data == e)
    {
        tmp = head;
        head = head->next;
        free(tmp);
        return 0;
    }
    q = head;
    while (q->next->next != NULL)
    {
        if (q->next->data == e)
        {
            tmp = q->next;
            q->next = tmp->next;
            free(tmp);
            return 0;
        }
        q = q->next;
    }
    if (q->next->data == e)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        return 0;
    }
}

int rev()
{
    struct node *p1, *p2, *p3;
    if (head->next == NULL)
    {
        return 0;
    }
    p1 = head;
    p2 = p1->next;
    p3 = p2->next;
    p1->next = NULL;
    p2->next = p1;
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
    }
    head = p2;
}

void count()
{
    int cnt = 0;
    struct node *q;
    q = head;
    while (q != NULL)
    {
        cnt += 1;
        q = q->next;
    }
    cout << "Total elements in the list are:- " << cnt << endl;
}

int search(int f)
{
    struct node *q;
    q = head;
    while (q != NULL)
    {
        if (q->data == f)
        {
            cout << "Item found" << endl;
            return 0;
        }
        q = q->next;
    }
    cout<<"Item not found"<<endl;
}


int main()
{
    head = NULL;
    int ch, n, v, d, pos, b, e, f;
    while (1)
    {
        cout << "0) Exit" << endl;
        cout << "1) Create" << endl;
        cout << "2) Display" << endl;
        cout << "3) Add at beginning" << endl;
        cout << "4) Add in between" << endl;
        cout << "5) Delete a node" << endl;
        cout << "6) Reverse list" << endl;
        cout << "7) Count total elements " << endl;
        cout << "8) Search a element " << endl;
        cout << "Enter your choice:- " << endl;
        cin >> ch;
        switch (ch)
        {
        case 0:
            exit(0);
            break;

        case 1:
            cout << "How many nodes will you want to create:- ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the element:- ";
                cin >> v;
                create(v);
            }
            break;

        case 2:
            display();
            break;

        case 3:
            cout << "Enter the element that you want to add at begining:- ";
            cin >> d;

            add_start(d);
            break;

        case 4:
            cout << "Enter the element that you want to add in between:- ";
            cin >> b;
            cout << "Enter the position:- ";
            cin >> pos;
            add_between(b, pos);
            break;

        case 5:
            cout << "Enter the element that you want to delete:- ";
            cin >> e;
            del(e);
            break;

        case 6:
            rev();
            break;

        case 7:
            count();
            break;

        case 8:
            cout << "Enter the element that you want to search:- " << endl;
            cin >> f;
            search(f);
            break;
        }
    }
}