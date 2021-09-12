#include <iostream>
using namespace std;

class node
{
    public:
    int colu;
    int val;
    node* next;
    friend class sparse;
};

class sparse
{
    int row;
    int col;
    node** n;

    public:
    void read();
    void display();
    friend sparse operator+(sparse, sparse);
};

void sparse::read()
{
    cout<<"enter the no of rows and columns: ";
    cin>>row>>col;

    n = new node* [row];
    node *p, *last;

    for(int i=0; i<row; i++)    { n[i] = 0; }
    for(int i=0; i<row; i++)
    {
        int no;
        cout<<"enter the no of non 0 elements in this row: ";
        cin>>no; 

        if(no == 0) {n[i] = 0;}
        else
            for(int j=0; j<no; j++)
            {
                p = new node;
                cout<<"enter the column no and value: ";
                cin>>p->colu>>p->val;
                p->next = 0;

                if(n[i]==0)
                    last = n[i] = p;
                else
                {
                    last->next = p;
                    last = p;
                }
            }
    }
}

void sparse::display()
{
    for(int i=0; i<row; i++)
    {
        node* t = n[i];
        if(t == 0)
        {
            for(int j=0; j<col; j++)
                cout<<"0 ";
        }
        else
            for(int j=0; j<col; j++)
            {
                if(j == t->colu)
                {
                    cout<<t->val<<" ";
                    if(t->next)
                        t = t->next;
                }
                else
                    cout<<"0 ";
            }
        cout<<endl;
    }
}

sparse operator+(sparse s1, sparse s2)
{
    if(s1.row == s2.row && s1.col == s2.col)
    {
        sparse *s3 = new sparse;
        s3->row = s1.row;
        s3->col = s1.col;
        s3->n = new node* [s3->row];
        
        node *t1, *t2, *p, *last;
        for(int a=0; a<s3->row; a++)
        {
            t1 = s1.n[a], t2 = s2.n[a];
            while(t1 && t2)
            {
                if(s3->n[a])
                    p = last = s3->n[a] = new node;
                else
                    p = new node;

                if(t1->colu < t2->colu)
                {
                    p->colu = t1->colu;
                    p->val = t1->val;
                    p->next = 0;
                    last->next = p;
                    last = p;
                    t1 = t1->next;
                }
                else if(t1->colu > t2->colu)
                {
                    p->colu = t2->colu;
                    p->val = t2->val;
                    p->next = 0;
                    last->next = p;
                    last = p;
                    t2 = t2->next;
                }
                else
                {
                    p->colu = t1->colu;
                    p->val = t1->val + t2->val;
                    p->next = 0;
                    last->next = p;
                    last = p;
                    t1 = t1->next;
                    t2 = t2->next;
                }
            }

            while(t1)
            {
                p = new node;
                p->colu = t1->colu;
                p->val = t1->val;
                p->next = 0;
                last->next = p;
                last = p;
                t1 = t1->next;
            }

            while(t2)
            {
                p = new node;
                p->colu = t2->colu;
                p->val = t2->val;
                p->next = 0;
                last->next = p;
                last = p;
                t2 = t2->next;
            }
        }
        return *s3;
    }
}

int main()
{
    sparse s1, s2;
    cout<<"sparse matrix 1: ";
    s1.read();
    s1.display();

    cout<<"sparse matrix 2: ";
    s2.read();
    s2.display();

    cout<<endl<<"addition matrix: "<<endl;
    sparse s3 = s1+s2;
    s3.display();
}