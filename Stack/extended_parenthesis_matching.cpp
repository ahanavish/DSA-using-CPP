#include <iostream>
#include <string.h>
using namespace std;

class node
{
    char data;
    node *next;
    friend class stack;
};

class stack
{
    node *top;

    public:
    stack() {top = 0;}

    bool balance(char *str)
    {
        int i=0;
        while(str[i])
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
                push(&str[i]);
            else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if(pop(str[i]) == 0)
                    return false;
            }
            i++;
        }
        if(top != 0)
            return false;
        else
            return true;
    } 

    void push(char *n)
    {
        node *t = new node;
        strcpy(&t->data, n);
        t->next = top;
        top = t;
    }
    int pop(char s)
    {
        if(top == 0)
          return 0;
        else if((top->data=='(' && s==')') || (top->data=='{' && s=='}') || (top->data=='[' && s==']') )
            {
                node *p = top;
                top = top->next;
                delete p;
                p = 0;
                return 1;
            }
            else
                return 0;
    }
};
int main()
{
    char s[] = "{(a+b)}";
    stack sta;
    if(sta.balance(s) == true)
        cout<<"-> Balanced";
    else
        cout<<"-> Not balanced";
}