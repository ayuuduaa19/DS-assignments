#include <iostream>
#include <stack>
using namespace std;
void ans(int arr[], int res[], int n)
{
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            res[i] = -1;
        }
        else
        {
            res[i] = s.top();
        }

        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int res[size];

    ans(arr, res, size);

    cout << "Nearest smaller to left: ";
    for (int i = 0; i < size; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
