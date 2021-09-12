#include <iostream>
using namespace std;

class array
{
    int A[5];
    int size;
    int length;
    public:
    void get()
    {
        size = 5;
        length = 5;

        cout<<"enter the elements: ";
        for(int i=0; i<length; i++)
            cin>>A[i];
    }
    friend int find(array, int);
};

int main()
{
    array arr;
    arr.get();

    int key;
    cout<<"enter the no to be searched: ";
    cin>>key;

    int t = find(arr, key);
    if(t == -1)
        cout<<"not found";
    else
        cout<<"found at: "<<t;
}

int find(array arr, int key)
{
    for(int i=0; i<arr.length; i++)
        if(arr.A[i] == key)
            return i;
    return -1;
}