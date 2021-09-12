#include <iostream>
using namespace std;

class queue
{
    int size;
    int rear;
    int front;
    int *arr;

    public:
    queue()
    {
        cout<<"enter the size: ";
        cin>>size;
        arr = new int[size];
        front = rear = -1;
    }

    void get()
    {
        cout<<"enter the elements: ";
        for(int i=0; i<size; i++)
        {
            cin>>arr[++rear];
        }
    }

    void put()
    {
        for(int i = 0; i<size; i++)
            if(arr[i] != -1)
            cout<<arr[i];
    }
    void deletee()
    {
        cout<<endl<<"deleting "<<arr[++front];
        arr[front] = -1;
    }

    int isempty()
    {
        if(front == rear)
            return 1;
        else 
            return 0;
    }
};

int main()
{
    queue q;
    q.get();
    q.put();
    q.deletee();
    cout<<endl<<"after deletion: ";
    q.put();
    if(q.isempty())
        cout<<endl<<"->empty";
    else  
        cout<<endl<<"->non empty";
}