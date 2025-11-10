#include <iostream>
#include <limits.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
};

Node *build(Node *root)
{
    int d;
    cout << "Enter data: ";
    cin >> d;

    if (d == -1)
        return NULL;

    root = new Node(d);

    cout << "Enter LEFT child of " << d << endl;
    root->left = build(root->left);

    cout << "Enter RIGHT child of " << d << endl;
    root->right = build(root->right);

    return root;
}
int sumleaf(Node *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    if (root->left != NULL)
    {
        if (root->left->left == NULL && root->left->right == NULL)
        {
            sum += root->left->data;
        }
    }
    sum += sumleaf(root->left);
    sum += sumleaf(root->right);
    return sum;
}
int main()
{
    Node *root = build(root);
    cout << "THE REQUIRED SUM IS :" << sumleaf(root);
}
