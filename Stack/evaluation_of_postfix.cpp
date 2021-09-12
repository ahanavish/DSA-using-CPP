#include <iostream>
#include <string.h>
using namespace std;

class node
{
    int data;
    node* next;
    friend class stack;
};

class stack
{
    node* top;
    char* post;

    public:
    stack(char* s)
    {
        post = s;
        top = 0;
    }
    ~stack()
    {
        while(top)
        {
            node* p = top;
            top = top->next;
            delete p;
        }
        delete top;
        delete post;
    }

    int evaluate()
    {
        int i=0, left = 0, right = 0, result=0;
        for(i=0; post[i]!='\0'; i++)
        {
            if(ifopnd(post[i]))
            {
                push(post[i]-'0');
            }
            else 
            {
                right = pop();
                left = pop();
                switch(post[i])
                {
                    case '+':
                            result = left + right;
                            push(result);
                            break;
                    case '-':
                            result = left - right;
                            push(result);
                            break;
                    case '*': 
                            result = left * right;
                            push(result);
                            break;
                    case '/':
                            result = left / right;
                            push(result);
                            break;
                }
            }
        }
        return top->data;
    }

    int ifopnd(char s)
    {
        if(s=='+' || s=='-' || s=='*' || s=='/')
            return 0;
        else
            return 1;
    }

    void push(int s)
    {
        node* t = new node;
        t->data = s;
        t->next = top;
        top = t;       
    }

    int pop()
    {
        node* p = top;
        int s = p->data;
        top = top->next;
        delete p;
        p = 0;
        return s;
    }
};
//234*+82/-         =10
int main()
{
    char post[100];          
    char* p;
    cout<<"enter the expression: ";
    cin>>post;
    p = post;
    stack st(p);

    cout<<"result: "<<st.evaluate();
}