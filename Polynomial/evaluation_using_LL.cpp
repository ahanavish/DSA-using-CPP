#include <iostream>
#include <math.h>
using namespace std;

class node
{
    int coeff;
    int exp;
    node *next;
    friend class ll;
};

class ll
{
    int n;
    node *head;

    public:
    ll()    
    {
        cout<<"enter no of terms: ";
        cin>>n;
        head = 0;
    }
    ~ll()
    {
        node *p = head;
        while(head)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }

    void get()
    {
        for(int i=0; i<n; i++)
        {
            node *p = new node, *last;
            cout<<"enter the coeff and exp: ";
            cin>>p->coeff>>p->exp;
            p->next = 0;

            if(head == 0)
                head = last = p;
            else
            {
                last->next = p;
                last = p;
            }
        }
    }  
    
    int value(int x)
    {
        node *p = head;
        int s=0;
        for(int i=0; i<n; i++)
        {
            int m = p->coeff;
            for(int j=0; j<p->exp; j++)
                m = m*x;
            s = s + m;
            p = p->next;
        }
        return s;
    } 
};

int main()
{
    ll l;
    l.get();
    int x;
    cout<<"enter the value of x: ";
    cin>>x;
    int t = l.value(x);
    cout<<"evaluated value: "<<t;
}