#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printTree(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << "Node : " << node->data << endl;
        if (node->left)
        {
            cout << "  Left child of " << node->data << " : " << node->left->data << endl;
            q.push(node->left);
        }
        if (node->right)
        {
            cout << "  Right child of " << node->data << " : " << node->right->data << endl;
            q.push(node->right);
        }
    }
}

int main()
{
    int x;
    cout << "Enter the root value : ";
    cin >> x;
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(x);
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << "Enter the left child of " << node->data << " (-1) if no child : ";
        cin >> x;
        if (x != -1)
        {
            node->left = new TreeNode(x);
            q.push(node->left);
        }
        cout << "Enter the right child of " << node->data << " (-1) if no child : ";
        cin >> x;
        if (x != -1)
        {
            node->right = new TreeNode(x);
            q.push(node->right);
        }
    }
    printTree(root);
}