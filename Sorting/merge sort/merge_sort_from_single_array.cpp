#include <iostream>
using namespace std;

int main()
{

    int end1 = 3, end2 = 7;

    int b[8];
    int i=0, j=end1+1, k=0;
    while(i<=end1 && j<=end2)
    {
        if(a[i]>a[j])
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }

    while(i<=end1)
        b[k++] = a[i++];

    while(j<=end2)
        b[k++] = a[j++];

    for(int t=0; t<end2+1; t++)
        cout<<b[t]<<" ";   
}