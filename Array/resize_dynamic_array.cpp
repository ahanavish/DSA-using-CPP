#include <iostream>
using namespace std;

int main()
{
    int *n = new int[4];
    
    cout<<"enter";
    for(int i=0; i<4; i++)
        cin>>n[i];

    int *m = new int[5];

    for(int i=0; i<4; i++)
        m[i] = n[i];
    
    m[4] = 5;

    delete []n;
    n = m;
    m = NULL;

    for(int i=0; i<5; i++)
        cout<<n[i];
}