#include <iostream>
using namespace std;

int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
   for (int j = p; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

void sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        sort(a, p, q - 1);
        sort(a, q + 1, r);
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

    sort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
