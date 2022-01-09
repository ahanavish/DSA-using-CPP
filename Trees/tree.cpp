// do not run individually
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class tree;

class node
{
    friend class tree;
    node *lchild;
    node *rchild;
    int data;
    int height;

public:
    void get(int c)
    {
        data = c;
        lchild = rchild = 0;
    }
    void nodeh(node *p)
    {
        int hl, hr;
        hl = p && p->lchild ? p->lchild->height : 0;
        hr = p && p->rchild ? p->rchild->height : 0;

        p->height = hl > hr ? hl + 1 : hr + 1;
    }

    friend void pre(node *);
    friend void in(node *);
    friend void post(node *);
};

class queue
{
    friend class tree;
    int size;
    int first;
    int last;
    node **arr;

public:
    void create()
    {
        arr = new node *[size];
        first = last = -1;
    }
    void enqueue(node *x)
    {
        if (first == -1)
            first = 0;
        arr[++last] = x;
    }
    int isempty()
    {
        if (first > last)
            return 1;
        else
            return 0;
    }
    node *dequeue()
    {
        node *x = arr[first];
        first++;
        return x;
    }
};

class tree
{
    node *p;
    node *t;

public:
    queue q;
    node *root;
    friend class node;
    tree(int size)
    {
        q.size = size;
        q.create();

        root = new node;
        cout << "enter root: ";
        cin >> root->data;
        root->lchild = root->rchild = 0;
        q.enqueue(root);
    }

    void process()
    {
        do
        {
            p = q.dequeue();
            int c;
            cout << "data of lchild of " << p->data << " : ";
            cin >> c;
            if (c != -1)
            {
                t = new node;
                t->get(c);
                p->lchild = t;
                q.enqueue(t);
            }

            cout << "data of rchild of " << p->data << " : ";
            cin >> c;
            if (c != -1)
            {
                t = new node;
                t->get(c);
                p->rchild = t;
                q.enqueue(t);
            }

            p->nodeh(p);
        } while (!q.isempty());
    }
};