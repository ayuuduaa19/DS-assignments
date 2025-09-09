#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();  
        q.push(x);            
        for (int i = 0; i < size; i++) {
            q.push(q.front());  
            q.pop();           
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << "Top after pop: " << s.top() << endl; 

    return 0;
}
