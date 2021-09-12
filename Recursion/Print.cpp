#include <iostream>
using namespace std;

void print(int);
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    print(n);
}

void print(int n)
{
    if(n>0)
    {
        
        cout<<n<<endl;        //calling(ascending)
        print(n-1);
        //cout<<n<<endl;          //returning(descending)
    }
}