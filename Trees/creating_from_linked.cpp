//do not run individually
#include <iostream>
using namespace std;
class tree;
class stack;

class node
{
    friend class tree;
    friend class stack;
    node* lchild;
    int data;
    node* rchild;

    public:
    void get(int c)
    {
        data = c;
        lchild = rchild = 0;
    }
    friend void pre(node*);
    friend void lvl(node*, tree);
};

class queue
{
    friend class stack;
    friend class tree;
    friend void lvl(node*, tree);
    int size;
    int first;
    int last;
    node **arr;

    public:
    void create()
    {
        arr = new node*[size];
        first = last = -1;
    }
    void enqueue(node* x)
    {
        if(first == -1)
            first = 0;
        arr[++last] = x;
    }
    int isempty()
    {
        if(first>last)
            return 1;
        else
            return 0;
    }
    node* dequeue()
    {
        node *x = arr[first];
        first++;
        return x;
    }
};

class stack
{
    node** arr;
    int first;
    int last;
    public:
    stack(int size)
    {
        arr = new node*[size];
        first = last = -1;
    }
    void push(node* t)
    {
        if(first == -1)
            first = 0;
        arr[++last] = t;
    }
    void process(node *p)
    {
        while(p || !isempty())
        {
            if(p)
            {
                cout<<p->data<<" ";
                push(p);
                p = p->lchild;
            }
            else
            {
                p = pop();
                p = p->rchild;
            }
        }
    }
    node* pop()
    {
        node* t = arr[last];
        last--;
        return t;
    }
    int isempty()
    {
        if(last<first)
            return 1;
        else 
            return 0;
    }
};

class tree
{
    friend void lvl(node*, tree);
    node *p;
    node *t;
    
    public:
    queue q;
    node *root;
    friend class stack;
    tree(int size)
    {
        q.size = size;
        q.create();

        root = new node;
        cout<<"enter root: ";
        cin>>root->data;
        root->lchild = root->rchild = 0;
        q.enqueue(root);
    }

    void process()
    {
        do
        {
            p = q.dequeue();
            int c;
            cout<<"data of lchild of "<<p->data<<" : ";
            cin>>c;
            if(c != -1)
            {
                t = new node;
                t->get(c);
                p->lchild = t;
                q.enqueue(t);
            }

            cout<<"data of rchild of "<<p->data<<" : ";
            cin>>c;
            if(c != -1)
            {
                t = new node;
                t->get(c);
                p->rchild = t;
                q.enqueue(t);
            }
        } while(!q.isempty());
    }
};
