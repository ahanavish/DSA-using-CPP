#include <iostream>
using namespace std;

class node
{
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
    sparse()
    {
        cout<<"enter the no of rows and columns: ";
        cin>>row>>col;
    }

    void read();
    void display();
};

void sparse:: read()
{   
    node* p, *last;
    n = new node* [row];
    for(int i=0; i<row; i++)    { n[i]=0; }

    for(int i=0; i<row; i++)
    {
        int no;
        cout<<"enter the no of elements in "<<i+1<<" row: ";
        cin>>no;

        for(int j=0; j<no; j++)
        {
            p = new node;
            cout<<"enter the column no and value: ";
            cin>>p->colu>>p->val;
            p->next = 0;

            if(n[i] == 0)
                last = n[i] = p;
            else
            {
                last->next = p;
                last = p;
            }
        }
    }
}

void sparse:: display()
{
    for(int i=0; i<row; i++)
    {
        node* t = n[i];
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

int main()
{
    sparse s;
    s.read();
    s.display();
}
