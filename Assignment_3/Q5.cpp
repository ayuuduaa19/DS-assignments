#include <iostream>
#include <stack>
using namespace std;
int calc(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    return 0;
}
int eval(string &postfix)
{
    stack<int> s;

    for (char ch : postfix)
    {
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            int ans = calc(num1, num2, ch);
            s.push(ans);
        }
    }
    return s.top();
}
int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result:" << eval(postfix) << endl;
    return 0;
}
