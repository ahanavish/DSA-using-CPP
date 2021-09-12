//not individually
#include "creating_from_linked.cpp"
#include <iostream>
using namespace std;

//recursive 
void pre(node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        pre(p->lchild);
        pre(p->rchild);
    }
}

int main()
{
    int size;
    cout<<"enter no of nodes: ";
    cin>>size;
    tree tr(size);
    tr.process();
    //tr.show();

    cout<<"preorder traversal: ";
    pre(tr.root);
}

/*iteration
int main()
{
    int size;
    cout<<"enter no of nodes: ";
    cin>>size;
    tree tr(size);
    tr.process();

    cout<<"preorder traversal: ";
    stack st(size);
    st.process(tr.root);
}*/