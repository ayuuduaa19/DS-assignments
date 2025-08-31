#include <iostream>
using namespace std;
int findlin(int arr[], int n)
{
    int sum = 0;
    int acsum = ((n + 1) * n) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
    }
    int key = acsum - sum;
    return key;
}
int binary(int arr[], int n)
{
    int beg = 0, end = n - 2;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (arr[mid] > mid + 1)
            end = mid - 1;
        else
            beg = mid + 1;
        return mid;
    }
    return -1;
}
int main()
{
    int arr[6] = {1, 2, 4, 5, 3, 7};
    cout << "Element missing" << endl;
    cout << "Using linear time:" << findlin(arr, 7) << endl;
    cout << "Using Binary search:" << findlin(arr, 7);
}