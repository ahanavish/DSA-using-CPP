//operands are not pushed into stack
#include <iostream>
#include <string.h>
#include <ctime>
#include <iomanip>
using namespace std;

class stack
{
    int size;
    int top;
    char *in;
    char *sta;

    public:
    stack(char *s)
    {
        in = s;
        size = strlen(s);
        top = -1;
        sta = new char[size+1];
    }
    ~stack()
    {
        delete []sta;
        in = 0;
        sta = 0;
    }

    char* convert()
    {
        int i=0, j=0;
        char *post = new char[size+1];
        while(in[i] != '\0')
            if(ifopnd(in[i]))
                post[j++] = in[i++];
            else
            {
                if(pre(in[i]) > pre(stacktop()))
                    push(in[i++]);
                else
                    post[j++] = pop();
            }
            
        while(!isempty())
            post[j++] = pop();

        post[j] = '\0';
        return post;
    }

    int ifopnd(char s)
    {
        if(s=='+' || s=='-' || s=='*' || s=='/')
            return 0;
        else
            return 1;
    }

    int stacktop()  {   return sta[top];    }

    int pre(char s)
    {
        if(s=='/' || s=='*')
            return 2;
        else if(s=='+' || s=='-')
            return 1;
        return 0;
    }

    void push(char s)   {   sta[++top] = s; }
    
    int pop()   {   return sta[top--];    }

    int isempty()
    {
        if(top == -1)
            return 1;
        else 
            return 0;
    }
};

//a+b*c-d/e
int main()
{
    time_t begin, end;
    time(&begin);

    cout<<"enter infix expression: ";
    char infix[10];
    gets(infix);
    cout<<"infix: "<<infix<<endl;
    stack st(infix);

    char *postfix = st.convert();
    cout<<"postfix: "<<postfix;

    time(&end);
    double time = double(end-begin);
    cout<<endl<<"-> Time taken: "<<fixed<<time<<setprecision(5);
    cout<<"sec"<<endl;
    return 0;
}