#include <iostream>
using namespace std;

int *h, sizeh=8;
void dele();
int main()
{
    cout<<"heap: ";
    h = new int[sizeh];
    //0,40,35,30,15,10,25,5
    for(int i=0; i<8; i++)
        cin>>h[i];

    int del;
    cout<<"enter the no of deletions to be made: ";
    cin>>del;       //for heap sort, enter 7
    for(int i=0; i<del; i++)
        dele();

    if(del==7)
    {
        cout<<"that's heapsort! "<<endl;
        for(int i=1; i<8; i++)
            cout<<h[i]<<" ";
    }
    else
    {
        cout<<"after required no of deletions: ";
        for(int i=1; i<sizeh; i++)
            cout<<h[i]<<" ";
    }

    return 0;
}

void dele()
{
    int temp = h[1];
    h[1] = h[sizeh-1];
    
    int j=1, k=2*j;
    while(k<sizeh-1)
    {
        if(h[k+1]>h[k])
            k++;

        if(h[k]>h[j])
        {
            int t=h[k];
            h[k] = h[j];
            h[j] = t;
            j=k;
            k=2*k;
        }
        else
            break;
    }
    h[sizeh-1] = temp;
    sizeh--;
}