#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int students[n], sandwiches[n];

    cout << "Enter student preferences (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++)
    {
        cin >> students[i];
    }

    cout << "Enter sandwiches (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++)
    {
        cin >> sandwiches[i];
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(students[i]);
    }

    int Index = 0;
    int x = 0;

    while (!q.empty() && x < q.size())
    {
        if (q.front() == sandwiches[Index])
        {
            q.pop();
            Index++;
            x = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
            x++;
        }
    }

    cout << "Number of students unable to eat: " << q.size() << endl;
    return 0;
}
