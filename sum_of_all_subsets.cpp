// C++ program to print sums of all possible
// subsets.
#include <iostream>
using namespace std;

// Prints sums of all subsets of arr[l..r]
void subsetSums(int arr[], int l, int r, int sum = 0)
{
    // Print current subset
    if (l > r)
    {
        cout << sum << " ";
        return;
    }

    // Subset including arr[l]
    subsetSums(arr, l + 1, r, sum + arr[l]);

    // Subset excluding arr[l]
    subsetSums(arr, l + 1, r, sum);
}

// Driver code
int main()
{
    int arr[] = {5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    subsetSums(arr, 0, n - 1);
    return 0;
}