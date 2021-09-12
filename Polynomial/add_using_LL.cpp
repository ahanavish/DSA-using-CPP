#include <iostream>
#include <math.h>

using namespace std;

class node
{
    public:
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
    ll()    { head = 0; }
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

    friend istream& operator>>(istream &in, ll &l)
    {
        cout<<"enter the no of terms: ";
        cin>>l.n;

        for(int i=0; i<l.n; i++)
        {
            node *p = new node, *last;
            cout<<"enter the coeff an exp for this term: ";
            in>>p->coeff>>p->exp;
            p->next = 0;

            if(l.head == 0)
                l.head = last = p;
            else
            {
                last->next = p;
                last = p;
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream &out, ll &l)
    {
        node *p = l.head;
        for(int i=0; i<l.n; i++)
        {
            out<<p->coeff<<" "<<p->exp<<endl;
            p = p->next;
        }
        return out;
    }

    friend ll operator+(ll l1, ll l2)
    {
        ll *l3 = new ll;
        node *p = l1.head, *q = l2.head, *r = 0, *last=0;
        l3->n = l1.n + l2.n;
        int k = 0;
        while(p && q)
        {
            if(l3->head == 0)
                r = last = l3->head = new node;
            else
                r = new node;

            if(p->exp > q->exp)
            {
                r->exp = p->exp;
                r->coeff = p->coeff;
                r->next = 0;
                last->next = r;
                last = r;
                p = p->next;
                r = r->next;
            }
            else if(p->exp < q->exp)
            {
                r->exp = q->exp;
                r->coeff = q->coeff;
                r->next = 0;
                last->next = r;
                last = r;
                q = q->next;
                r = r->next;
            }
            else
            {
                r->exp = p->exp;
                r->coeff = p->coeff + q->coeff;
                r->next = 0;
                last->next = r;
                last = r;
                p = p->next;
                q = q->next;
                r = r->next;
            }
            k++;
        }

        while(p)
        {
            r = new node;
            r->exp = p->exp;
            r->coeff = p->coeff;
            r->next = 0;
            last->next = r;
            last = r;
            p = p->next;
            r = r->next;
            k++;
        }

        while(q)
        {
            r = new node;
            r->exp = q->exp;
            r->coeff = q->coeff;
            r->next = 0;
            last->next = r;
            last = r;
            q = q->next;
            r = r->next;   
            k++;
        }
        l3->n = k;
        return *l3;
    }
};

int main()
{
    ll l1, l2, l3;
    cin>>l1>>l2;
    l3 = l1+l2;
    cout<<l3;
}