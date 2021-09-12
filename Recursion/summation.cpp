#include <iostream>
using namespace std;

int sum(int);
int main()
{
    int n;
    cout<<"enter a no: ";
    cin>>n;
    cout<<sum(n);
}
int sum(int n)
{
    if(n>0)
        return n+sum(n-1);
    else    
        return 0;
}