#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *BT(int x)
{
    if (x == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(x);
    int data;
    cout << "Enter the Left Child of " << x << " (-1 if no Left Child) : ";
    cin >> data;
    root->left = BT(data);
    cout << "Enter the right child of " << x << " (-1 if no Right Child) : ";
    cin >> data;
    root->right = BT(data);
    return root;
}

TreeNode *RemoveHalfNodes(TreeNode *root)
{
    if (!root)
    {
        return NULL;
    }
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if (!root->left && root->right)
    {
        return root->right;
    }
    if (root->left && !root->right)
    {
        return root->left;
    }
    return root;
}

int main()
{
    int x;
    cout << "Enter the root of BT : ";
    cin >> x;
    TreeNode *root = BT(x);
}