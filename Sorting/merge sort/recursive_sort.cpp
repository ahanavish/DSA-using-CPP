#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits.h>
using namespace std;

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
}

int main()
{
    time_t begin, end;
    time(&begin);
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);
    cout << endl
         << endl
         << "-> After sorting: ";
    printArray(arr, arr_size);

    time(&end);
    double time = double(end - begin);
    cout << endl
         << "-> Time taken: " << fixed << time << setprecision(5);
    cout << "sec" << endl;
    return 0;
}