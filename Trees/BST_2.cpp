#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class node
{
    node *lchild;
    int val;
    node *rchild;
    friend class tree;
};

class tree
{
public:
    node *root;
    tree()
    {
        root = 0;
    }
    void recursive()
    {
        int size = 0;
        cout << "enter the no of nodes: ";
        cin >> size;

        int e;
        cout << "enter the elements randomly: ";
        cin >> e;
        root = insert(root, e);
        node *p;
        for (int i = 1; i < size; i++)
        {
            cin >> e;
            p = insert(root, e);
        }
    }
    int height(node *p)
    {
        int x, y;
        if (p == 0)
            return 0;
        x = height(p->lchild);
        y = height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }
    node *inpre(node *p) // inorder predecessor
    {
        while (p && p->rchild != 0)
            p = p->rchild;
        return p;
    }
    node *insucc(node *p) // inorder successor
    {
        while (p && p->lchild != 0)
            p = p->lchild;
        return p;
    }
    node *insert(node *p, int e)
    {
        node *t;
        if (p == 0)
        {
            t = new node;
            t->val = e;
            t->lchild = t->rchild = 0;
            return t;
        }

        if (e < p->val)
            p->lchild = insert(p->lchild, e);
        else if (e > p->val)
            p->rchild = insert(p->rchild, e);
        return p;
    }
    void deletee(int d)
    {
        delete_no(root, d);
    }
    node *delete_no(node *p, int d)
    {
        node *q;
        if (p == 0)
            return NULL;

        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
                root = NULL;
            delete p;
            return NULL;
        }

        if (d < p->val)
            p->lchild = delete_no(p->lchild, d);
        else if (d > p->val)
            p->rchild = delete_no(p->rchild, d);
        else
        {
            if (height(p->lchild) > height(p->rchild))
            {
                q = inpre(p->lchild);
                p->val = q->val;
                p->lchild = delete_no(p->lchild, q->val);
            }
            else
            {
                q = insucc(p->rchild);
                p->val = q->val;
                p->rchild = delete_no(p->rchild, q->val);
            }
        }
        return p;
    }

    void show()
    {
        show_pre(root);
        cout << endl;
    }
    void show_pre(node *p)
    {
        if (p)
        {
            cout << p->val << " ";
            show_pre(p->lchild);
            show_pre(p->rchild);
        }
    }
};

int main()
{
    time_t begin, end;
    time(&begin);

    int option = 0;
    cout << "options are: " << endl
         << "1. insertion" << endl
         << "2. deletion" << endl
         << "3. print" << endl
         << "choosen option: ";
    cin >> option;

    tree tr;

    int again = 0;
repeat:
    if (again == 1)
    {
        cout << "options are: " << endl
             << "1. insertion" << endl
             << "2. deletion" << endl
             << "3. print" << endl
             << "choosen option: ";
        cin >> option;
    }

    switch (option)
    {
    case 1:
        tr.recursive();
        break;

    case 2:
        int d;
        cout << "enter the no to be deleted: ";
        cin >> d;
        tr.deletee(d);
        break;

    case 3:
        tr.show();
        break;
    }

    cout << endl
         << "any other operation(1/0): ";
    cin >> again;
    if (again == 1)
        goto repeat;
    else if (again == 0)
        cout << "end!";
    else
        cout << "wrong input";

    time(&end);
    double time = double(end - begin);
    cout << endl
         << "-> Time taken: " << fixed << time << setprecision(5);
    cout << "sec" << endl;
    return 0;
}