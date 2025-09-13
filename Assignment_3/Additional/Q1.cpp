#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> smallest(vector<int> &A)
{
    stack<int> s;
    vector<int> res;
    for (int i = 0; i < A.size(); i++)
    {
        while (!s.empty() && s.top() >= A[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(s.top());
        }
        s.push(A[i]);
    }

    return res;
}

int main()
{
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = smallest(A);

    cout << "Nearest smaller to left: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}
