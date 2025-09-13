#include <iostream>
#include <stack>
using namespace std;
class Stack
{
    stack<int> s;
    int min;
public:
    void push(int x)
    {
        if (s.empty())
        {
            s.push(0);
            min = x;
        }
        else
        {
            s.push(x - min);
            if (x < min)
            {
                min = x;
            }
        }
    }

    void pop()
    {
        if (s.empty())
            return;
        int diff = s.top();
        s.pop();
        if (diff < 0)
        {
            min = min - diff;
        }
    }
    int top()
    {
        int diff = s.top();
        if (diff >= 0)
            return min + diff;
        else
            return min;
    }

    int getMin()
    {
        return min;
    }
    bool empty()
    {
        return s.empty();
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Min: " << s.getMin() << endl;
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Min: " << s.getMin() << endl;
    cout << "Top: " << s.top() << endl;
    return 0;
}
