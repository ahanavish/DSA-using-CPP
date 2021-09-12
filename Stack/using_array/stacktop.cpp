#include <iostream>
using namespace std;

class stack
{
    int size;
    int top;
    int *s;

    public:
    stack()
    {
        cout<<"enter the size: ";
        cin>>size;
        s = new int[size];
        top = -1;

        if(size != 0)
            cout<<"enter the elements: ";
        for(int i=0; i<size; i++)
            cin>>s[++top];
    }
    ~stack()
    {
        delete []s;
        s = 0;
    }

    void display()
    {
        for(int i=top; i>-1; i--)
            cout<<s[i]<<" ";
    }

    void whattop()
    {
        if(top == -1)
            cout<<"no elements in the stack";
        else
            cout<<s[top];
    }
};

int main()
{
    stack s1;
    s1.display();
    s1.whattop();
}