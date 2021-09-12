#include <iostream>
using namespace std;

class array
{
    int *A;
    int length;
    int size;
    public:
    array()
    {
        cout<<"enter size: ";
        cin>>size;
        length = size;
        A = new int [size];

        cout<<"enter the elements in sorted manner: ";
        for(int i=0; i<length; i++)
            cin>>A[i];
    }

    friend int find(array, int);
};

int main()
{
    array arr;
    int key;
    cout<<"enter the no to be searched: ";
    cin>>key;

    int t = find(arr, key);
    if(t == -1)
        cout<<"not found";
    else
        cout<<"found at: "<<t+1<<" position";
}

int find(array arr, int key)
{
    int mid = arr.size/2, min = 0, max = arr.length-1;

    while(max>min)
    {
        if(key>arr.A[mid])
        {
            min = mid+1;
            mid = mid + mid/2;
        }
        else if(key == arr.A[mid])
            return mid;
        else
        {
            max = mid-1;
            mid = mid/2;
        }
    }
    return -1;
}
