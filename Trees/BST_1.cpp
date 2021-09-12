#include <iostream>
using namespace std;

class tree;
class queue;

class node
{
    node* lchild;
    int val;
    node* rchild;
    friend class tree;
    public:
    void get(int c)
    {
        val = c;
        lchild = rchild = 0;
    }
};

class queue
{
    node** arr;
    int first;
    int last;
    int size;
    public:
    queue()
    {
        arr = new node* [size];
        first = last = -1;
    }
    friend class tree;
    void enqueue(node *p)
    {
        if(first == -1)
            first = 0;

        arr[++last] = p;
    }

    node* dequeue()
    {
        node *p = arr[first++];
        return p;
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
    int size;
    node* root;
    public:
    friend class stack;
    queue q;
    tree(int size, int option)
    {
        this->size = size;
        if(option == 4)
            make();
        else if(option == 1)
        {
            cout<<"enter the root: ";
            root = new node;
            cin>>root->val;
            root->lchild = root->rchild = 0;
            q.enqueue(root);
            create();
        }
    }
    void make()
    {
        int a[size];
        cout<<"enter the elements: ";
        for(int i=0; i<size; i++)
            cin>>a[i];

        node* p = new node;
        root = p;
        p->get(a[0]);

        for(int i=1; i<size; i++)
        {
            node* t = new node;
            t->get(a[i]);
            if(a[i]>a[i-1])
            {
                p->rchild = t;
                p = p->rchild;
            }
            else
            {
                p->lchild = t;
                p = p->lchild;
            }
        }
    }
    void create()
    {
        node* p = 0;
        node* t = 0;
        int i=0, child = 0;
        do
        {
            p = q.dequeue();
            int c = 0;
            cout<<"data of lchild of "<<p->val<<" : ";
            cin>>c;
            if(c != -1)
            {
                t = new node;
                t->get(c);
                p->lchild = t;
                q.enqueue(t);
            }
            
            cout<<"data of rchild of "<<p->val<<" : ";
            cin>>c;
            if(c != -1)
            {
                t = new node;
                t->get(c);
                p->rchild = t;
                q.enqueue(t);
            }
        }while(!q.isempty());
    }

    void search(int s, int i)
    {
        node* p = root;
        node* qu = 0;
        int t=0;
        while(p)
        {
            if(p->val == s)
            {
                if(i == -1)
                {
                    cout<<"found!";
                    t = 1;
                    break;
                }
                else
                {
                    cout<<"already present!";
                    t = 1;
                    break;
                }
            }
            else if(s>p->val)
            {
                if(i != -1)
                    qu = p;
                p = p->rchild;
            }
            else 
            {
                if(i != -1)
                    qu = p;
                p = p->lchild;  
            }
        }

        if(t == 0 && i == -1)
            cout<<"not found!";
        else if(t == 0 && i != -1)
        {
            node* t = new node;
            t->get(i);

            if(s>qu->val)
                qu->rchild = t;
            else
                qu->lchild = t;
        }
    }
    void show()
    {
        show_pre(root);
    }
    void show_pre(node* p)
    {
        if(p)
        {
            cout<<p->val<<" ";
            show_pre(p->lchild);
            show_pre(p->rchild);
        }
    }
};

int main()
{
    int option = 0, size = 0;
    cout<<"options: "<<endl<<"1. directly create BST"<<endl<<"2. search"<<endl<<"3. insert"<<endl<<"4. creating from array"<<endl<<"5. print"<<endl<<"choosen option: ";
    cin>>option;
    cout<<"no of nodes: ";
    cin>>size;
    tree tr(size, option);

    int again = 0;
    repeat:
    if(again==1)
    {
        cout<<"options: "<<endl<<"1. directly create BST"<<endl<<"2. search"<<endl<<"3. insert"<<endl<<"4. creating from array"<<endl<<"5. print"<<endl<<"choosen option: ";
        cin>>option;
    }

    switch(option)
    {
        case 1:     break;

        case 2:     int s;
                    cout<<"enter the no to be found: ";
                    cin>>s;
                    tr.search(s, -1);
                    break;

        case 3:     int i;
                    cout<<"enter the no to be inserted: ";
                    cin>>i;
                    tr.search(s, i);
                    break;
        
        case 4:     break;

        case 5:     tr.show();
                    break;
    }

    cout<<endl<<"any other operation(1/0): ";
    cin>>again;
    if(again==1)
        goto repeat;
    else
        cout<<"end!";
}