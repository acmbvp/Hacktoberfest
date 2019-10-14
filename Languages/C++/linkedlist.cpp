#include<iostream>
using namespace std;


class node
{
public:
    int data;
    node*next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};


class LinkedList
{
   private:
    node*head;
    node*tail;
    int size;

    void displayreverse(node*temp)
    {
        if(temp==NULL)
        {
            return;
        }
        displayreverse(temp->next);
        cout<<temp->data<<" ";
    }

    public:

    LinkedList()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }



    //to input data
    void inputdata()
    {
        int data;
        cin>>data;

        while(data!=-1)
        {
            node*newnode=new node(data);

            if(this->head==NULL)
            {
                this->head=newnode;
                this->tail=newnode;
            }

            else{
                this->tail->next=newnode;
                this->tail=newnode;
            }

            this->size++;
            cin>>data;
        }
    }





    //to display data
    void display()
    {
        node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }





    //if size of list is 0
    void handlesize0case(int data)
    {
        node*newnode=new node(data);
        this->head=newnode;
        this->tail=newnode;
        this->size++;
    }




    //add element at last
    void addlast(int data)
    {
        if(size==0)
        {
            handlesize0case(data);
            return;
        }

        node*newnode=new node(data);

        this->tail->next=newnode;
        this->tail=newnode;

        this->size++;
    }




    //add element at first
    void addfirst(int data)
    {
         if(size==0)
        {
            handlesize0case(data);
            return;
        }

        node*newnode=new node(data);

        newnode->next=head;
        this->head=newnode;

        this->size++;

    }



    //get first element
    int getfirst()
    {
        if(size==0)
        {
            cout<<"list is empty";
            return -1;
        }
        return head->data;
    }




    //get last element
    int getlast()
    {
        if(size==0)
        {
            cout<<"list is empty";
            return -1;
        }
        return tail->data;
    }



    //get element at specific index
    int getat(int index)
    {
        if(index<0 || index>=this->size)
        {
            cout<<"invalid index";
            return -1;
        }
        if(size==0)
        {
            cout<<"list is empty";
            return -1;
        }

        node*temp=head;
        int lv=0;
        while(lv!=index)
        {
            temp=temp->next;
            lv++;
        }

        return temp->data;
    }





    //get node of specific index
     node* getnodeat(int index)
    {
        if(index<0 || index>=this->size)
        {
            cout<<"invalid index";
            return NULL;
        }
        if(size==0)
        {
            cout<<"list is empty";
            return NULL;
        }

        node*temp=head;
        int lv=0;
        while(lv!=index)
        {
            temp=temp->next;
            lv++;
        }

        return temp;
    }



    //add element at specific index
    void addat(int data,int index)
    {
        if(size==0)
        {
          node*newnode=new node(data);
          this->size++;
          head=newnode;
          tail=newnode;
          return;
        }
        else if(index==0)
        {
            addfirst(data);
            return;
        }else if(index==this->size-1)
        {
            addlast(data);
            return;
        }else if(index<0 || index>=this->size)
        {
            cout<<"invalid index";
            return;
        }

        node*nm1=getnodeat(index-1);
        node*np1=getnodeat(index);
        node*newnode=new node(data);
        nm1->next=newnode;
        newnode->next=np1;
        this->size++;

    }


    //handle remove case for size=1
    int handlecasesize1()
    {
            node*ntr=head;
            head=NULL;
            tail=NULL;
            int data=ntr->data;
            delete ntr;
            this->size--;
            return data;
    }


    //to remove first element
    int removefirst()
    {
        if(size==0)
        {
            cout<<"list is empty";
            return -1;
        }
        if(size==1)
        {
           int data= handlecasesize1();
           return data;
        }
       node*ntr=head;
       this->head=this->head->next;
       int data=ntr->data;
       delete ntr;
       this->size--;
       return data;

    }



    //remove last element
    int removelast()
    {
        if(size==0)
        {
            cout<<"list is empty";
            return -1;
        }
        if(size==1)
        {
            int data= handlecasesize1();
           return data;
        }
        node*ntr=tail;
        node*temp=getnodeat(this->size-2);
        temp->next=NULL;
        int dd=ntr->data;
        delete ntr;
        this->size--;
        return dd;
    }

    //display reverse
    void displayreverse()
    {
        node*temp=this->head;
        displayreverse(temp);
    }



    //remove element at index
    int removeat(int index)
    {
        if(size==0)
        {
            cout<<"list is empty";
            return -1;
        }
        else if(index<0 || index>=this->size)
        {
            cout<<"invalid arguements";
        }
        else if(index==1)
        {
            int ans=removefirst();
            return ans;
        }
        else if (index==this->size-1)
        {
            int ans=removelast();
            return ans;
        }
        node*nm1=getnodeat(index-1);
        node*nn=nm1->next;
        node*np1=nn->next;

        nm1->next=np1;

        int dd=nn->data;
        delete nn;
        this->size--;

        return dd;
    }



};






int main()
{
   LinkedList*list=new LinkedList();
   list->inputdata();
   cout<<"display data"<<endl;
   list->display();

    cout<<endl<<"adding 10 at last";
   cout<<endl;

   list->addlast(10);
    list->display();

    cout<<endl<<"adding 20 at first";
    cout<<endl;

   list->addfirst(20);
    list->display();

    cout<<endl<<"printing first element";
    int data=list->getfirst();
    cout<<endl<<data;

    cout<<endl<<"printing last element";
    data=list->getlast();
    cout<<endl<<data;

    cout<<endl<<"getting element at index 5";
    data=list->getat(5);
    cout<<endl<<data;

    cout<<endl<<"getting node at index 4";
    node*dd=list->getnodeat(4);
    cout<<endl<<dd;
    cout<<endl<<dd->data;

    cout<<endl<<"adding element 49 at index 3";
    list->addat(49,3);
    cout<<endl;
    list->display();

    cout<<endl<<"removing first element";
    data=list->removefirst();
    cout<<endl<<data;

    cout<<endl<<"removing last element";
     data=list->removelast();
    cout<<endl<<data;

    cout<<endl<<"display reverse";
    cout<<endl;
    list->displayreverse();


    cout<<endl<<"remove at index 3";
    data=list->removeat(3);
    cout<<endl<<data;
}
