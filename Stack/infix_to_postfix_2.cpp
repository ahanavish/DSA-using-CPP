#include <iostream>
#include <string.h>
using namespace std;

class stack
{
    int size;
    int top;
    char *sta;
    char *in;

    public:
    stack(char *s)
    {
        size = strlen(s);
        in = s;
        sta = new char[size+1];
        top = -1;
    }
    ~stack()
    {
        delete []sta;
        sta = 0;
        in = 0;
    }

    char* convert()
    {
        int i=0, j=0;
        char* post = new char[size+1];
        while (in[i] != '\0')
        {
            if(i==0)
                push(in[i++]);
            
            if(pre(in[i])> pre(stacktop()))
                push(in[i++]);
            else
                post[j++] = pop();
        }
        
        while(!isempty())
            post[j++] = pop();

        post[j] = '\0';
        return post;
    }

    int stacktop()
    {
        return sta[top];
    }

    int pre(char s)
    {
        if(s>='a' && s<='z')
            return 3;
        else if(s=='*' || s=='/')
            return 2;
        else if(s=='+' || s=='-')
            return 1;
        else 
            return 0;
    }

    void push(char s)
    {
        sta[++top] = s;
    }

    int pop()
    {
        return sta[top--];
    }

    int isempty()
    {
        if(top == -1)
            return 1;
        else 
            return 0;
    }
};

int main()
{
    char infix[] = "a+b*c-d/e";
    cout<<"infix: "<<infix<<endl;
    stack st(infix);
    char *postfix = st.convert();
    cout<<"postfix: "<<postfix;
}