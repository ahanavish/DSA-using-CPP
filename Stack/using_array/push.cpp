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
        cout<<"enter the size of stack: ";
        cin>>size;
        top = -1;
        s = new int [size]; 
    }
    ~stack()        //destructor
    {
        delete []s;
        s = 0;
    }
    void push(int n)
    {
        top++;
        s[top] = n;
    }
    void display();
};

void stack::display()
{
    int end = top;
    while(! (end < 0))
        cout<<s[end--]<<" ";
}

int main()
{
    stack s1;
    int neww;
    cout<<"enter the elements to be inserted: ";
    for(int i=0; i<s1.size; i++)
    {
        cin>>neww;
        s1.push(neww);
    }

    cout<<"stack(from the top): ";
    s1.display();
}