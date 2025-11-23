#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

void printPre(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val;
    printPre(root->left);
    printPre(root->right);
}

Node *copyTree(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *temp = new Node(root->val);
    temp->left = copyTree(root->left);
    temp->right = copyTree(root->right);
    return temp;
}

int makeBST(int begin, int finish, Node *out[])
{
    if (begin > finish)
    {
        out[0] = NULL;
        return 1;
    }

    int idx = 0;

    for (int rootVal = begin; rootVal <= finish; rootVal++)
    {

        Node *leftArr[200];
        Node *rightArr[200];

        int leftCnt = makeBST(begin, rootVal - 1, leftArr);
        int rightCnt = makeBST(rootVal + 1, finish, rightArr);

        for (int i = 0; i < leftCnt; i++)
        {
            for (int j = 0; j < rightCnt; j++)
            {

                Node *root = new Node(rootVal);
                root->left = copyTree(leftArr[i]);
                root->right = copyTree(rightArr[j]);

                out[idx++] = root;
            }
        }
    }

    return idx;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    Node *result[2000];
    int total = makeBST(1, n, result);

    for (int i = 0; i < total; i++)
    {
        cout << "Tree " << i + 1 << ": ";
        printPre(result[i]);
        cout << endl;
    }
    return 0;
}
