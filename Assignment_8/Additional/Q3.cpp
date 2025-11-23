#include <iostream>
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

int maxdepth(Node *root)
{
    if (root == NULL)
        return 0;
    int leftd = maxdepth(root->left);
    int rightd = maxdepth(root->right);
    return 1 + max(leftd, rightd);
}

void inorder(Node *&root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = build(root);
    cout << "\nPRINTING INORDER TRAVERSAL: ";
    inorder(root);
    cout << "\nMAX DEPTH OF BST IS:" << maxdepth(root);

    return 0;
}
