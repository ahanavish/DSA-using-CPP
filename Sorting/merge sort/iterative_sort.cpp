#include <iostream>
using namespace std;

#define N 8
 
int min(int x, int y) {return (x < y) ? x : y; }
 
void merge(int A[], int temp[], int from, int mid, int to)
{
    int k = from, i = from, j = mid + 1;
    while (i <= mid && j <= to)
    {
        if (A[i] < A[j]) 
            temp[k++] = A[i++];
        else 
            temp[k++] = A[j++];
    }
 
    while (i < N && i <= mid) 
        temp[k++] = A[i++];
 
    for (int i = from; i <= to; i++)
        A[i] = temp[i];
}
 
void mergesort(int A[], int temp[], int low, int high)
{
    for (int m = 1; m <= high - low; m = 2*m)
        for (int i = low; i < high; i += 2*m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, high);
 
            merge(A, temp, from, mid, to);
        }
}
 
int printArray(int A[])
{
    for (int i = 0; i < N; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
 
int main()
{
    int A[N] = {8, 3, 7, 4, 9, 2, 6, 5};
    int temp[N];
    for(int i=0; i<N; i++)
        temp[i] = A[i];

    cout<<"Original array: ";
    printArray(A);

    mergesort(A, temp, 0, N - 1);
    cout<<"Modified array: ";
    printArray(A);
    return 0;
}