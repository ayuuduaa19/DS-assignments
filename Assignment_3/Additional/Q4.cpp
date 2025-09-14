#include <iostream>
#include <stack>
using namespace std;
void temperature(int temps[], int ans[], int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && temps[s.top()] <= temps[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            ans[i] = s.top() - i;
        }
        else
        {
            ans[i] = 0;
        }
        s.push(i);
    }
}
int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    int temps[n], ans[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++)
    {
        cin >> temps[i];
    }
    temperature(temps, ans, n);
    cout << "Days to wait for warmer temperature:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
