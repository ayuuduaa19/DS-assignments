#include <iostream>
#include <queue>
#include <climits>
using namespace std;
void sort(queue<int> &q)
{
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int minVal = INT_MAX;
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            int curr = q.front();
            q.pop();
            if (j < size - i && curr < minVal)
                minVal = curr;
            q.push(curr);
        }
        bool skipped = false;
        for (int j = 0; j < size; j++)
        {
            int curr = q.front();
            q.pop();
            if (!skipped && curr == minVal && j < size - i)
            {
                skipped = true;
                continue;
            }
            q.push(curr);
        }
        q.push(minVal);
    }
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(1);
    q.push(4);
    q.push(2);
    q.push(5);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sort(q);

    cout << "Sorted Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
