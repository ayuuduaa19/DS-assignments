#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverse(Node *head, int k)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverse(next, k);
        if (head->next != NULL)
            head->next->prev = head;
    }

    return prev;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;

    for (int i = 2; i <= 9; i++)
    {
        Node *newNode = new Node(i);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    cout << "Original list:\n";
    print(head);

    int k = 3;
    head = reverse(head, k);

    cout << "Reversed in groups of " << k << ":\n";
    print(head);

    return 0;
}
