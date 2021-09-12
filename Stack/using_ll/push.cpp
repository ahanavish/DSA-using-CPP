#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;
    friend class stack;
};

class stack
{
    node* top;
    int size;

    public:
    stack()    {top = 0;}
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

    void push()
    {
        cout<<"enter the size: ";
        cin>>size;

        if(size != 0)
        {
            cout<<"enter the elements: ";
            for(int i=0; i<size; i++)
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
};

int main()
{
    stack s1;
    s1.push();
    s1.display();
}