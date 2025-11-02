#include <iostream>
#include <cmath>
using namespace std;

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int l[100], rarr[100];
    for (int i = 0; i < n1; i++)
        l[i] = a[p + i];
    for (int j = 0; j < n2; j++)
        rarr[j] = a[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (l[i] <= rarr[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = rarr[j];
        j++;
        k++;
    }
}

void sort(int a[], int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2);
        sort(a, p, q);
        sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main() {
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
