#include <iostream>
using namespace std;

int power(int, int);
int main()
{
    int n, x;
    cout<<"enter power and no: ";
    cin>>n>>x;
    cout<<power(n, x);
}

int power(int n, int x)
{
    if(n>0)
        return x*(n-1, x);
    else   
        return 1;
}