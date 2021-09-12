#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;
    friend class ll;
};

class ll
{
    node *first;
    public:
    ll()    {first = 0;};
    
    void insert(int neww)
    {
        node *t, *last;
        t = new node;
        t->data = neww;
        t->next = 0;
        if(first == 0)
            first = last = t;
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

    void delete_ele(int del)
    {
        node *p = first, *q;
        while(p)
        {
            if(p->data == del)
            {
                if(p == first)
                    first = p->next;
                else
                    q->next = p->next;
                p->next = 0;
                delete p;
                break;
            }
            q = p;
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
    cout<<"enter the elements: ";
    for(int i=0; i<no; i++)
    {
        cin>>neww;
        l.insert(neww);
    }

    cout<<"before deletion: ";
    l.display();

    int del;
    cout<<endl<<"enter the element which needs to be deleted: ";
    cin>>del;
    l.delete_ele(del);

    cout<<"after deletion: ";
    l.display();
    return 0;
}