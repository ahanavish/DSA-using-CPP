#include <iostream>
using namespace std;

void insert(int h[], int);
int main()
{
    
    int *h;
    h = new int[8];
    //0,10,20,30,25,5,40,35
    cout<<"enter: ";
    for(int i=0; i<8; i++)
        cin>>h[i];

    for(int i=1; i<8; i++)
        cout<<h[i]<<" ";
    for(int i=1; i<8; i++)
        insert(h, i);

    cout<<endl<<"created heap: ";
    for(int i=1; i<8; i++)
        cout<<h[i]<<" ";    
}

void insert(int h[], int i)
{
    int temp = h[i];

    while(i>1 && temp>h[i/2])
    {
        h[i] = h[i/2];
        i = i/2;
    }
    h[i] = temp;
}