#include <iostream>
using namespace std;

int main()
{
    int **a;
    a = new int *[2];
    a[0] = new int [2];
    a[1] = new int [2];

    cout<<"enter: "<<endl;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            cin>>a[i][j];

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
            cout<<a[i][j]<<ends;
    cout<<endl;
    }
}