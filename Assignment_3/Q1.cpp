#include <iostream>
using namespace std;
#define MAX 5
class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = data;
            cout << data << " pushed into stack." << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, underflow condition." << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack s;

    int choice, val;

    while (true)
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            s.push(val);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is not Empty." << endl;
            break;
        case 6:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is not Full." << endl;
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}