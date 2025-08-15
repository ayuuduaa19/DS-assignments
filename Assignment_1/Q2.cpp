#include <iostream>
using namespace std;
void dup(int arr[], int size)
{

    int index = 0;
    for (int i = 0; i < size; i++)
    {
        bool isdup = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] == arr[j])
            {
                isdup = 1;
                break;
            }
        if (!isdup)
        {
            arr[index++] = arr[i];
        }
    }
    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 2, 4};
    dup(arr, 5);
}