#include <iostream>
using namespace std;

class node
{
    int ele;
    node* next;
    friend class queue;
};

class queue
{
    node* front;
    node* rear;

    public:
    queue() { front = rear = 0; }

    void insert(int x)
    {
        node* t;
        t = new node;
        t->ele = x;
        t->next = 0;

        if(front == 0)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }

    void deletee()
    {
        node* t = front;
        cout<<"deleting "<<t->ele<<endl;
        front = front->next;
        delete t;
        t = 0;
    }

    void display()
    {
        node* t = front;
        do
        {
            cout<<t->ele<<endl;
            t = t->next;
        }while(t);
    }
};

int main()
{
    queue q;
    q.insert(1);
    q.insert(2);
    q.deletee();
    q.insert(3);
    q.display();
}