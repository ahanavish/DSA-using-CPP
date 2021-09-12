#include <iostream>
using namespace std;

class node
{
    int data;
    node* next;
    friend class stack;
};

class stack
{
    node* top;

    public:
    int size;
    stack() {top = 0;}
    ~stack()
    {
        node *p = top;
        while(top)
        {
            top = top->next;
            delete p;
            p = top;
        }
    }

    void insert()
    {
        cout<<"enter size: ";
        cin>>size;

        if(size != 0)
        {
            cout<<"enter the elements: ";
            for(int i=0 ;i<size; i++)
            {
                node *t = new node;
                cin>>t->data;
                t->next = top;
                top = t;
            }
        }
        else
            cout<<"empty stack! ";
    }

    void display()
    {
        node *p = top;
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }

    int pop()
    {
        node *t = top;
        top = top->next;
        int x = t->data;
        delete t;
        t = 0;
        return x;
    }
};

int main()
{
    stack s1;
    s1.insert();
    if(s1.size != 0)
    {
        cout<<"before popping: ";
        s1.display();
        int x = s1.pop();
        cout<<endl<<"after popping "<<x<<" : ";
        s1.display();
    }
}