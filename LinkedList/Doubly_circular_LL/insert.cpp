#include <iostream>
using namespace std;

class node
{
    node *prev;
    int data;
    node *next;
    friend class ll;
};

class ll
{
    node *head;
    public:
    ll()    {head = 0;};
    
    void insert(int neww)
    {
        node *t, *last;
        t = new node;
        t->data = neww;
        if(head == 0)
        {
            t->prev = t;
            t->next = t;
            head = last = t;
        }
        else
        {
            last->next = t;
            t->prev = last;
            t->next = head;
            last = t;
            head->prev = last;
        }
    }

    void display()
    {
        node *p = head;
        do
        {
            cout<<p->data<<ends;
            p = p->next;
        }while(p != head);
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

    cout<<"elements are: ";
    l.display();
}