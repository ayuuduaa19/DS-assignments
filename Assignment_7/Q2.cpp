#include <iostream>
using namespace std;

void sort(int a[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int min = start;
        int max = start;
        for (int i = start; i <= end; i++)
        {
            if (a[i] < a[min])
                min = i;
            if (a[i] > a[max])
                max = i;
        }
        swap(a[start], a[min]);
        if (max == start)
            max = min;
        swap(a[end], a[max]);

        start++;
        end--;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
