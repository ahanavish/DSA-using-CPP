#include <iostream>
#include <string.h>
using namespace std;

class stack
{
    int size;
    int top;
    char *sta;
    char *str;

    public: 
    stack(char *s)
    {
        str = s;
        size = strlen(s);
        top = -1;
        sta = new char[size];
    }
    ~stack()
    {
        delete []sta;
        sta = 0;
    }

    bool balance()
    {
        int i=0;
        while(str[i] != '\0')
        {
            if(str[i] == '(')
                push(str[i]);
            else if(str[i] == ')')
                if(pop() == 0)
                    return false;
            i++;
        }

        if(top == -1)
            return true;
        else
            return false;
    }

    void push(int n)
    {
        top++;
        sta[top] = n;
    }

    int pop()
    {
        if(top == -1)
            return 0;
        sta[top] = -10;
        top--;
        return 1;
    }
};

int main()
{
    char s[] = "(a+b)*(c/6)";
    stack st(s);

    if(st.balance() == true)
        cout<<"-> Balanced";
    else
        cout<<"-> Not balanced";
}