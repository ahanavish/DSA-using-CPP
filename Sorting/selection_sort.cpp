#include <iostream>
using namespace std;

int main()
{
    int a[] = {5,4,6,2,3};

    for(int i=0; i<5; i++)
    {
        int min=1000, k=0;
        for(int j=i; j<5; j++)
        {
            if(min>a[j])
            {
                min = a[j];
                k = j;
            }
        }
        int temp = a[k];
        a[k] = a[i];
        a[i] = temp; 
    }

    for(int i=0; i<5; i++)
        cout<<a[i]<<" ";
}