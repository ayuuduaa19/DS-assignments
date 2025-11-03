#include <iostream>
using namespace std;

#define N 3

class Node
{
public:
    int data;
    Node *next, *prev, *up, *down;
    Node(int d)
    {
        data = d;
        next = prev = up = down = NULL;
    }
};

Node *list(int mat[N][N])
{
    Node *head = NULL;
    Node *prevRow[N] = {NULL};

    for (int i = 0; i < N; i++)
    {
        Node *prev = NULL;
        for (int j = 0; j < N; j++)
        {
            Node *curr = new Node(mat[i][j]);
            if (!head)
                head = curr;

            if (prev)
            {
                prev->next = curr;
                curr->prev = prev;
            }
            if (prevRow[j])
            {
                prevRow[j]->down = curr;
                curr->up = prevRow[j];
            }
            prevRow[j] = curr;
            prev = curr;
        }
    }
    return head;
}

void display(Node *head)
{
    Node *row = head;
    while (row)
    {
        Node *col = row;
        while (col)
        {
            cout << col->data;
            if (col->next)
                cout << " <-> ";
            else
                cout << " -> NULL";
            col = col->next;
        }
        cout << endl;

        if (row->down)
            cout << "  |      |      |" << endl;
        else
            cout << "NULL <-> NULL <-> NULL" << endl;

        row = row->down;
    }
}

int main()
{
    int mat[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Node *head = list(mat);
    cout << "Doubly Linked List Representation:\n\n";
    display(head);

    return 0;
}
