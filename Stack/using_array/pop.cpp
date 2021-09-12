#include <iostream>
using namespace std;

class stack
{
    public:
    int size;
    int top;
    int *s;

    stack()
    {
        cout<<"enter the size: ";
        cin>>size;
        s = new int[size];
        cout<<"enter elements: ";
        int i;
        for(i=0; i<size; i++)
            cin>>s[i];
        top = i-1;
    }
    ~stack()
    {
        delete []s;
        s = 0;
    }

    int pop()
    {
        if(top == -1)
            cout<<"stack underflow";
        else
        {
            int p = s[top];
            top --;
            return p;
        }
    }

    void display()
    {
    int end = top;
    while(! (end < 0))
        cout<<s[end--]<<" ";
    }
};

int main()
{
    stack s1;
    cout<<"before deletion: ";
    s1.display();
    int p = s1.pop();
    cout<<endl<<"after deletion of "<<p<<" : ";
    s1.display();
}