#include <iostream>
using namespace std;

class node
{
    int data;
    node* next;
    friend class ll;
};

class ll
{
    node* first;

    public:
    ll()    {first = 0;};
    ~ll()
    {
        node *p = first;
        while(first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }
    void insert(int neww)
    {
        node *t, *last;
        t = new node;
        t->data = neww;
        t->next = 0;
        if(first == 0)
        {
            first = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }

    void display()
    {
        node *p = first;
        while(p)
        {
            cout<<p->data<<ends;
            p = p->next;
        }
    }
};

int main()
{
    int no, neww;
    cout<<"enter the no of elements to be added: ";
    cin>>no;

    ll l;
    for(int i=0; i<no; i++)
    {
        cin>>neww;
        l.insert(neww);
    }
    l.display();
}