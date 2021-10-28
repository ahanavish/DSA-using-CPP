#include <iostream>
using namespace std;

int main()
{
    int a[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6}, max=-1;

    for(int i=0; i<10; i++)
        if(max<a[i])
            max = a[i];

    int b[max+1] = {0};
    for(int i=0; i<10; i++)
        b[a[i]]++;

    int i=0, j=0;
    while(i<max+1)
    {
        if(b[i]>0)
        {
            a[j++] = i;
            b[i]--;
        }
        else
            i++;
    }

    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";
}