#include <iostream>
using namespace std;

#define MAXLEN 100

class Stack
{
    char arrLen[MAXLEN];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAXLEN - 1;
    }
    void push(char a)
    {
        if (!isFull())
        {
            arrLen[++top] = a;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            arrLen[top--];
        }
    }
    void display()
    {
        cout << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arrLen[i];
        }
        cout << endl;
    }
    char peek()
    {
        if (!isEmpty())
        {
            return arrLen[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
};

int main()
{
    string a = "DataStructure";
    Stack b;
    for (int i = 0; i < a.length(); i++)
    {
        b.push(a[i]);
    }
    Stack rev;
    while (!b.isEmpty())
    {
        rev.push(b.peek());
        b.pop();
    }
    rev.display();
    return 0;
}