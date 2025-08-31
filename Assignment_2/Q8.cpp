
#include <iostream>
using namespace std;

int distinct(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        bool isDup = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDup = true;
                break;
            }
        }
        if (!isDup)
            count++;
    }
    return count;
}

int main()
{
    int arr[5] = {1, 2, 1, 3, 3};
    cout << "Total distinct elements = " << distinct(arr, 5);
}
