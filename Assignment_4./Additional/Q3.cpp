#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool check(queue<int> q)
{
    stack<int> s;
    int expected = 1;
    int n = q.size();
    while (!q.empty())
    {
        if (q.front() == expected)
        {
            q.pop();
            expected++;
        }
        else if (!s.empty() && s.top() == expected)
        {
            s.pop();
            expected++;
        }
        else
        {
            s.push(q.front());
            q.pop();
        }
    }
    while (!s.empty() && s.top() == expected)
    {
        s.pop();
        expected++;
    }

    return (expected == n + 1);
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (check(q))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
