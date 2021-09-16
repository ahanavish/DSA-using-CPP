//not individually
//////cant get the answer
#include "creating_from_linked.cpp"
#include <iostream>
using namespace std;

int main()
{
    int size;
    cout<<"enter no of nodes: ";
    cin>>size;
    tree tr(size);
    tr.process();

    cout<<"preorder traversal of unbalanced tree: ";
    pre(tr.root);
    tr.root = tr.avl(tr.root);
    cout<<endl<<"preorder traversal of balanced tree: ";
    pre(tr.root);
}

void pre(node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        pre(p->lchild);
        pre(p->rchild);
    }
}