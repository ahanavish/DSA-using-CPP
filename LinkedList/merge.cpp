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

    void merge(ll l2)
    {
        node *firstt, *last, *second = l2.first;
        if(first->data >= second->data)
        {
            last = firstt = second;
            second = second->next;
            last->next = 0;
        }
        else    
        {
            last = firstt = first;
            first = first->next;
            last->next = 0;
        }

        while(first && second)
        {
            if(first->data <= second->data)
            {
                last->next = first;
                last = first;
                first = first->next;
                last->next = 0;
            }
            else
            {
                last->next = second;
                last = second;
                second = second->next;
                last->next = 0;
            }
        }
        if(first)
            last->next = first;
        else
            last->next = second;

        first = firstt;
    }
};

int main()
{
    int no1, no2, neww;
    cout<<"enter the no of elements to be inserted in ll1 and ll2: ";
    cin>>no1>>no2;

    ll l1, l2;
    cout<<"enter the elements for 1st ll: ";
    for(int i=0; i<no1; i++)
    {
        cin>>neww;
        l1.insert(neww);
    }
    cout<<"enter the elements for 2nd ll: ";
    for(int i=0; i<no2; i++)
    {
        cin>>neww;
        l2.insert(neww);
    }

    cout<<"1st ll before merging: ";
    l1.display();
    cout<<endl<<"2nd ll before merging: ";
    l2.display();

    l1.merge(l2);

    cout<<endl<<"after merging: ";
    l1.display();
}