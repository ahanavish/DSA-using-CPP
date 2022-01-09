#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits.h>
using namespace std;

int partition(int a[], int l, int h);
void quick(int a[], int l, int h);
int main()
{
    time_t begin, end;
    time(&begin);

    cout << "before: ";
    int a[] = {2, 5, 3, 6, 4, INT_MAX};
    int i = 0, j = 6;
    for (int i = 0; i < j - 1; i++)
        cout << a[i] << " ";

    quick(a, 0, j - 1);

    cout << endl
         << endl
         << "-> after sorting: ";
    for (int i = 0; i < j - 1; i++)
        cout << a[i] << " ";

    time(&end);
    double time = double(end - begin);
    cout << endl
         << "-> Time taken: " << fixed << time << setprecision(5);
    cout << "sec" << endl;
    return 0;
}

int partition(int a[], int l, int h)
{
    int pivot = a[l], i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (j > i);

    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quick(int a[], int l, int h)
{
    int j = 0;
    if (l < h)
    {
        j = partition(a, l, h);
        quick(a, l, j);
        quick(a, j + 1, h);
    }
}