#include <iostream>
using namespace std;

int sumarray(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    return arr[0] + sumarray(arr + 1, size - 1);
}

int main()
{
    int arr[] = { 1,2,3,4,5 };

    int size = 5;

    int sum = sumarray(arr, size);

    cout << "sum of array elements " << sum << endl;

    return 0;
}