#include <iostream>
using namespace std;

class stack
{
    public:
    int size;
    int top;
    int* s;

    stack()
    {
        cout<<"enter the size: ";
        cin>>size;
        s = new int [size];
        int i;
        cout<<"enter the elements: ";
        for(i=0; i<size; i++)
            cin>>s[i];
        top = i-1;
    }
    ~stack()
    {
        delete []s;
        s = 0;
    }

    void peek(int index)
    {
        if(top-index < 0)
            cout<<"invalid index! ";
        else
            cout<<"element: "<<s[top-index];
    }
};

int main()
{
    stack s1;
    int index;
    cout<<"enter the index to be peeked at: ";
    cin>>index;
    s1.peek(index-1);
}