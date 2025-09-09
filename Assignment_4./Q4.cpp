#include <iostream>
#include <queue>
using namespace std;
void ans(string str)
{
    queue<char> q;
    int freq[256] = {0};
    for (char ch : str)
    {
        q.push(ch);
        freq[ch]++;
        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }
        if (q.empty())
            cout << -1;
        else
            cout << q.front();
    }
    cout << endl;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    ans(input);

    return 0;
}
