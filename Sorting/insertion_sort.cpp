#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits.h>
using namespace std;

int main()
{
    time_t begin, end;
    time(&begin);

    int a[] = {8, 5, 7, 3, 2};
    cout << "before: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";

    for (int i = 1; i < 5; i++)
    {
        int j = i - 1, temp = a[i];
        while (j >= 0)
        {
            if (a[j] > a[j + 1] || a[j] > temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                break;
        }
        a[j + 1] = temp;
    }

    cout << endl
         << endl
         << "-> after sorting: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";

    time(&end);
    double time = double(end - begin);
    cout << endl
         << "-> Time taken: " << fixed << time << setprecision(5);
    cout << "sec" << endl;
    return 0;
}