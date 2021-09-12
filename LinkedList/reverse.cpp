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
    public:
    node *first;
    ll()    {first = 0;};

    void insert(int neww)
    {
        node *t, *last;
        t = new node;
        t->data = neww;
        t->next = 0;
        if(first == 0)
            last = first = t;
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

    void reverse()                                  //by reversing links(using two tail pointers)
    {
        node *p = first, *q = 0, *r = 0;
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }

    /*void reverse(node *p, node *q)            //by recursion
    {

        if(p)
        {
            reverse(p->next, p);
            p->next = q;
        }
        else
            first = q;
    }*/
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

    cout<<"before reverse: ";
    l.display();

    //l.reverse(l.first, 0);                      //by recursion
    l.reverse();                                  //by reversing links(using two tail pointers)
    cout<<endl<<"after reverse: ";
    l.display();
}
