//not individually
#include "creating_from_linked.cpp"
#include <iostream>
using namespace std;

void lvl(node* p, tree tr)
{
    cout<<p->data<<" ";
    tr.q.enqueue(p);
    while(!tr.q.isempty())
    {
        p = tr.q.dequeue();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            tr.q.enqueue(p->lchild);
        }

        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            tr.q.enqueue(p->rchild);
        }
    }
}

int main()
{
    int size;
    cout<<"enter no of nodes: ";
    cin>>size;
    tree tr(size);
    tr.process();

    cout<<"levelorder traversal: ";
    lvl(tr.root, tr);
}