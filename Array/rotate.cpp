#include <iostream>
using namespace std;

class array
{
    int *a;
    int size;
    int length;
    public:
    array()
    {
        cout<<"enter length: ";
        cin>>length;
        size = length;
        a = new int [length];

        cout<<"enter the elements: ";
        for(int i=0; i<length; i++)
            cin>>a[i];
    }
    friend void rotate1(array*);
    friend void rotate(int, array*);
};

int main()
{
    array arr;
    
    int no;
    cout<<"how many times array needs to be rotated: ";
    cin>>no;

    rotate(no, &arr);
}

void rotate(int no, array* arr)
{
    cout<<"before rotation: "<<endl;
    for(int i=0; i<arr->length; i++)
        cout<<arr->a[i]<<ends;

    for(int i=0; i<no; i++)
        rotate1(arr);

    cout<<endl<<"after required no of rotations: "<<endl;
    for(int i=0; i<arr->length; i++)
        cout<<arr->a[i]<<ends;
}

void rotate1(array* arr)
{
   int store = arr->a[arr->length-1]; 
    for(int i=arr->length-1; i>0; i--)
        arr->a[i] = arr->a[i-1]; 
    arr->a[0] = store;
}