#include <iostream>
using namespace std;
int search(int arr[], int size, int key)
{
    int beg = 0, end = size - 1;
    while (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[5] = {1, 2, 3, 5, 4};
    cout << "Element found at index:" << search(arr, 5, 1) << endl;
}