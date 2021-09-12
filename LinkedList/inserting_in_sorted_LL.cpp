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

    void insert_at_sorted(int neww)
    {
        node *p=first, *t, *q;

        t =new node;
        t->data = neww;
        t->next = 0;
        while(p && neww > p->data)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }    
    }
};

int main()
{
    int no, neww;
    cout<<"enter the no of elements to be inserted: ";
    cin>>no;

    ll l;
    cout<<"enter the elements: ";
    for(int i=0; i<no; i++)
    {
        cin>>neww;
        l.insert(neww);
    }

    cout<<"before insertion: ";
    l.display();

    cout<<endl<<"enter the no to be inserted at sorted ll: ";
    cin>>neww;
    l.insert_at_sorted(neww);

    cout<<"after insertion: ";    
    l.display();
}