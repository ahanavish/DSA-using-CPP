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
            t->next = t;
            t->prev = t;
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
        } while (p != head);
    }

    void delete_ind(int ind)
    {
        node *p = head, q;
        for(int i=1; i<ind; i++)
            p = p->next;
        if(ind == 1)
            head = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
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

    int ind;
    cout<<endl<<"enter the index to be deleted: ";
    cin>>ind;
    l.delete_ind(ind);

    cout<<"after deletion: ";
    l.display();
}