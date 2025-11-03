#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node() {}
};
int countOnes(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return count;
}

Node *remove(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        int ones = countOnes(curr->data);
        if (ones % 2 == 0)
        {
            Node *del = curr;
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            curr = curr->next;
            delete del;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(18);
    Node *n2 = new Node(15);
    Node *n3 = new Node(8);
    Node *n4 = new Node(9);
    Node *n5 = new Node(14);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    cout << "Original Linked list:";
    print(head);

    head = remove(head);

    cout << "After removing even parity nodes: ";
    print(head);
}
