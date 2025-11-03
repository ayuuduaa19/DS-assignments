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
};

void fix(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->prev != temp)
        {
            cout << "Fixed link at node" << temp->next->data << endl;
            temp->next->prev = temp;
        }
        temp = temp->next;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 3; i++)
    {
        temp->next = new Node(i);
        temp->next->prev = temp;
        temp = temp->next;
    }

    head->next->next->prev = head;

    cout << "Before fixing: ";
    print(head);

    fix(head);

    cout << "After fixing:  ";
    print(head);

    return 0;
}
