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
    ll()    {first = 0;}
    ll(int a[], int n)
    {
        node *last, *t;
        first = new node;
        first->data = a[0];
        first->next = 0;
        last = first;
        for(int i=1; i<n; i++)
        {
            t = new node;
            t->data = a[i];
            t->next = 0;
            last->next = t;
            last = t;
        }
    }
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

    void display()
    {
        node *p = first;

        while(p)
        {
            cout<<p->data<<ends;
            p = p->next;
        }
        delete p;
    }
    void insert(int neew, int pos)
    {
        node *p, *t;
        if(pos == 0)
        {
            t = new node;
            t->data = neew;
            t->next = first;
            first = t;
        }
        else if(pos>0)
        {
            p = first;
            for(int i=0; i<pos-1 && p; i++)
                p = p->next;
            if(p)
            {
                t = new node;
                t->data = neew;
                t->next = p->next;
                p->next = t;
            }
        }
    }
};

int main()
{
    int n;
    cout<<"enter the no of elements: ";
    cin>>n;

    int a[n];
    cout<<"enter the elements: ";
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    ll l(a, n);
    l.display();

    int neww, poss;
    cout<<endl<<"enter the no and the position at which it needs to be inserted: ";
    cin>>neww>>poss;
    l.insert(neww, poss);
    l.display();
}