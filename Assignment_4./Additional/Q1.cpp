#include <iostream>
#include <queue>
#include <string>
using namespace std;
void generate(int n)
{
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++)
    {
        string s = q.front();
        q.pop();
        cout << s;
        if (i != n - 1)
            cout << ",";
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ":";
    generate(n);

    return 0;
}
