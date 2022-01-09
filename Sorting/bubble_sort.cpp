#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    time_t begin, end;
    time(&begin);

    int a[] = {2, 1, 5, 7, 4, 9};
    cout << "before: ";
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";

    int flag = 1, i = 0;
    do
    {
        flag = 0;
        i++;
        for (int j = 0; j < 6 - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
    } while (flag);

    cout << endl
         << endl
         << "-> after sorting: ";
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";

    time(&end);
    double time = double(end - begin);
    cout << endl
         << "-> Time taken: " << fixed << time << setprecision(5);
    cout << "sec" << endl;
    return 0;
}