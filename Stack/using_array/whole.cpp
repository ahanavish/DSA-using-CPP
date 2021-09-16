#include <iostream>
#include <ctime>
#include <iomanip>
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
        cout<<"enter elements to push: ";
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
            cout<<"--> stack underflow";
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

    void peek(int index)
    {
        if(top-index < 0)
            cout<<"--> invalid index! ";
        else
            cout<<"--> element found : "<<s[top-index];
    }

    void whattop()
    {
        if(top == -1)
            cout<<"--> no elements in the stack!";
        else
            cout<<"--> elements at top: "<<s[top];
    }

    void isempty()
    {
        if(top == -1)
            cout<<"--> stack is empty";
        else
            cout<<"--> stack is not empty";
    }
};

int main()
{
    time_t begin, end;
    time(&begin);

    stack s1;
    cout<<endl<<"--> elements in stack: ";
    s1.display();
    int o;
    repeat:
    cout<<endl<<endl<<"choose the option: "<<endl<<"1. pop"<<endl<<"2. peek"<<endl<<"3. stacktop"<<endl<<"4. isempty"<<endl;
    cin>>o;
    if(o==1)
    {
        int p = s1.pop();
        cout<<endl<<"--> after deletion of "<<p<<" : ";
        s1.display();
    }
    else if(o==2)
    {
        int index;
        cout<<endl<<"--> enter the index to be peeked at: ";
        cin>>index;
        s1.peek(index-1);
    }
    else if(o==3)
        s1.whattop();
    else if(o==4)
        s1.isempty();

    int again;
    cout<<endl<<"--> Would you like to perform another operation(1/ 0): ";
    cin>>again;
    if(again==1)
        goto repeat;
    else
        cout<<endl<<"exit!";

    time(&end);
    double time = double(end-begin);

    cout<<endl<<"-> Time taken: "<<fixed<<time<<setprecision(5);
    cout<<"sec"<<endl;
    return 0;
}