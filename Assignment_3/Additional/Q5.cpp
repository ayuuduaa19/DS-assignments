#include <iostream>
#include <stack>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool check(int A[], int n)
{
    int sorted[n];
    for (int i = 0; i < n; i++)
    {
        sorted[i] = A[i];
    }

    bubbleSort(sorted, n);

    stack<int> s;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        s.push(A[i]);

        while (!s.empty() && s.top() == sorted[index])
        {
            s.pop();
            index++;
        }
    }

    return (index == n);
}

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    if (check(A, n))
    {
        cout << "Possible to sort array B into ascending order." << endl;
    }
    else
    {
        cout << "Not possible to sort array B into ascending order." << endl;
    }

    return 0;
}
