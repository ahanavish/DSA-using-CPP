#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout<<"ttt";
    vector <int> v;
    for(int i=0 ; i<5; i++)
        v.push_back(i);
    for(int i=0; i<5; i++)
        cout<<v.at(i)<<endl;
    return 0;
}