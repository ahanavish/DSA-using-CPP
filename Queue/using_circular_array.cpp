#include <iostream>
using namespace std;

class queue
{
    int size;
    int front;
    int rear;
    int *arr;

    public:
    queue()
    {
        int t;
        cout<<"enter the size: ";
        cin>>t;
        size = t+1;
        front = rear = 0;
        arr = new int[size];
    }
    
    ~queue()    {delete []arr; arr = 0;}

    void insert(int x)
    {
        if((rear+1)%size == front)
            cout<<"full, cant add further"<<endl;
        else
        {
            rear = (rear+1)%size;
            arr[rear] = x;
        }
    }

    void deletee()
    {
        if(front == rear)
            cout<<"empty, cant delete"<<endl;
        else
        {
            front = (front+1)%size;
            cout<<"deleting "<<arr[front]<<endl;
            arr[front] = -1;
        }
    }

    void put()
    {
        int f=front+1;
        do
        {
            cout<<arr[f];
            f = (f+1)%size;
        }while(f!=(rear+1)%size);
        cout<<endl;
    }
};

int main()
{                                                                     //initially before putting:
    queue q;                                                           //|  3  |  2   |    |  1  |
    q.insert(3);                                                         //      rear  front
    q.insert(2);
    q.insert(1);
    q.deletee();
    q.deletee();
    q.insert(2);
    q.insert(3);
    q.put();
}