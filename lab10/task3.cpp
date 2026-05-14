#include<iostream>
using namespace std;

int findmax(int arr[], int size)
{
    
    if (size == 1)
    {
        return arr[0];
    }

    
    int maxremaining = findmax(arr + 1, size - 1);

    
    if (arr[0] > maxremaining)
    {
        return arr[0];
    }
    else
    {
        return maxremaining;
    }
}

int main()
{
    int arr[] = { 12, 5, 18, 7, 3 };

    int size = 5;

    cout << "Maximum element: "
        << findmax(arr, size);

    return 0;
}