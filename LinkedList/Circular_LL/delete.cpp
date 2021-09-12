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
            head = last = t;
            t->next = head;
        }
        else
        {
            last->next = t;
            t->next = head;
            last = t;
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

    void delete_ele(int del)
    {
        node *p = head, *q;
        do
        {
            q = p;
            p = p->next;
        }while(p != head);

        p = head;
        do
        {
            if(del == p->data)
            {
                if(p == head)
                    head = p->next;
                q->next = p->next;
                p->next = 0;
                delete p;
                break;
            }
            q = p;
            p = p->next;
        }while(p != head);
    }
};

int main()
{
    int no, neww, del;
    cout<<"enter the no of elements: ";
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

    cout<<endl<<"enter the element to be deleted: ";
    cin>>del;
    l.delete_ele(del);

    cout<<"after deletion: ";
    l.display();
}