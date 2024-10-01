#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printBT(TreeNode *root)
{
    if (!root)
        cout << "No nodes ";
    cout << "TREE IS " << endl;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    queue<TreeNode *> q;
    int x;
    int leftChild, rightChild;
    cout << "Enter root : ";
    cin >> x;
    TreeNode *root = new TreeNode(x);
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << "Enter left child of " << temp->data << " (-1 if no left child) : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            temp->left = new TreeNode(leftChild);
            q.push(temp->left);
        }
        cout << "Enter right child of " << temp->data << " (-1 if no left child) : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            temp->right = new TreeNode(rightChild);
            q.push(temp->right);
        }
    }
    printBT(root);
}