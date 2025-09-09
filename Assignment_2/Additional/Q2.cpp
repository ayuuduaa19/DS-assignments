#include <iostream>
#include <string>
using namespace std;
bool Split(string &s)
{
    int n = s.size();
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);
            if ((B.find(A) != string::npos && C.find(A) != string::npos) ||
                (A.find(B) != string::npos && C.find(B) != string::npos) ||
                (A.find(C) != string::npos && B.find(C) != string::npos))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s;
    cout << "Enter a string:";
    cin >> s;

    if (Split(s))
        cout << "can split" << endl;
    else
        cout << "cannot split" << endl;
    return 0;
}
