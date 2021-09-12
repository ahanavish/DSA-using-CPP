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
    ll(int a[], int no)
    {
        node *t, *last;
        head = new node;
        head->data = a[0];
        head->prev = head;
        head->next = head;
        last = head;
        for(int i=1; i<no; i++)
        {
            t = new node;
            t->data = a[i];
            t->prev = last;
            last->next = t;
            t->next = head;
            last = t;
        }
        head->prev = last;
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
    int no;
    cout<<"enter the no of elements to be inserted: ";
    cin>>no;

    int a[no];
    for(int i=0; i<no; i++)
        cin>>a[i];
        
    ll l(a, no);

    cout<<"elements are: ";
    l.display();
}