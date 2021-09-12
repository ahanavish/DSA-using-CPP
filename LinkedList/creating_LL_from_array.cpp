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
    private:
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
    }
};

int main()
{
    int n;
    cout<<"enter the no of elements in the array: ";
    cin>>n;

    int a[n];
    cout<<"enter the elements: ";
    for(int i=0; i<n; i++)
        cin>>a[i];

    ll l(a, n);
    l.display();
}