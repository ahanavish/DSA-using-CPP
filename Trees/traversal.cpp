// not individually
#include "tree.cpp"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// recursive
void pre(node *p)
{
    if (p)
    {
        cout << p->data << " ";
        pre(p->lchild);
        pre(p->rchild);
    }
}

void in(node *p)
{
    if (p)
    {
        in(p->lchild);
        cout << p->data << " ";
        in(p->rchild);
    }
}

void post(node *p)
{
    if (p)
    {
        post(p->lchild);
        post(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    time_t begin, end;
    time(&begin);

    int size;
    cout << "enter no of nodes: ";
    cin >> size;
    tree tr(size);
    tr.process();
    // tr.show();

    cout << endl
         << "-> pre-order traversal: ";
    pre(tr.root);

    cout << endl
         << "-> in-order traversal: ";
    in(tr.root);

    cout << endl
         << "-> post-order traversal: ";
    post(tr.root);

    time(&end);
    double time = double(end - begin);
    cout << endl
         << "-> Time taken: " << fixed << time << setprecision(5);
    cout << "sec" << endl;
    return 0;
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