#include <iostream>
#include <stack>
using namespace std;
void res(int arr[], int ans[], int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = -1;

        s.push(arr[i]);
    }
}
int main()
{
    int size;
    cout << "Enter size:";
    cin >> size;

    int arr[size], ans[size];
    cout << "Enter elements:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    res(arr, ans, size);

    cout << "Next Greater Elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " -> " << ans[i] << endl;
    }

    return 0;
}
