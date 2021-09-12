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
    ll(int a[], int n)
    {
        node *last, *t;
        head = new node;
        head->data = a[0];
        head->next = head;
        last = head;

        for(int i=1; i<n; i++)
        {
            t= new node;
            t->data = a[i];
            t->next = head;
            last->next = t;
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
};

int main()
{
    int no;
    cout<<"enter the no of elements: ";
    cin>>no;

    int a[no];
    cout<<"enter the elements: ";
    for(int i=0; i<no; i++)
        cin>>a[i];

    ll l(a, no);
    cout<<"elements are: ";
    l.display();
}