#include <iostream>
using namespace std;

int main()
{
    int a1[] = {2, 18, 100}, a2[] = {4};
    int a3[4];

    int i=0, j=0, k=0;
    while(i<3 && j<1)
    {
        if(a1[i]>a2[j]) 
            a3[k++] = a2[j++];
        else 
            a3[k++] = a1[i++];
    }

    while(i<3)
        a3[k++] = a1[i++];

    while(j<1)
        a3[k++] = a2[j++];

    for(int t=0; t<4; t++)
        cout<<a3[t]<<" ";
}