#include <iostream>
using namespace std;

class tree;
class node
{
    node* lchild;
    int val;
    node* rchild;
    friend class tree;
    friend class stack;
};

class stack
{
    int down;
    int up;
    node** array;
    public:
    friend class tree;
    friend class node;
    stack(int size)
    {
        up = down = -1;
        array = new node*[size];
    }
    void push(node* p)
    {
        array[++up] = p;
    }
    int peek()
    {
        if(empty())
            return 10000;
        return array[up]->val;
    }
    node* pop()
    {
        if(up == -1)
            return 0;
        else
        {
            node* p = array[up];
            up --;
            return p;
        }
    }
    int empty()
    {
        if(up == -1)
            return 1;
        else
            return 0;
    }
};

class tree
{
    node* root;
    int size;
    int *arr;
    friend class stack;
    public:
    tree(int size)
    {
        this->size = size;
        arr = new int[size];

        cout<<"enter the elements: ";
        for(int i=0; i<size; i++)
            cin>>arr[i];
        
        bst();
    }
    void bst()
    {
        stack s(size);
        int i=0;
        root = new node;
        root->val = arr[i++];
        root->lchild = root->rchild = NULL;

        node* p = root;
        node* t;
        while(i < size)
        {
            if(arr[i]<p->val)
            {
                t = new node;
                t->val = arr[i++];
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                s.push(p);
                p = t;
            }
            else 
            if(arr[i]>p->val && arr[i]<s.peek())
            {
                t= new node;
                t->val = arr[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
                p = s.pop();
        }
    }
    void show()
    {
        show_in(root);
    }
    void show_in(node* p)
    {
        if(p != NULL)
        {
            show_in(p->lchild);
            cout<<p->val<<" ";
            show_in(p->rchild);
        }
    }
};

int main()
{
    int size;
    cout<<"enter the size: ";
    cin>>size;
    
    tree tr(size);
    cout<<"inorder: ";
    tr.show();
    return 0;
}