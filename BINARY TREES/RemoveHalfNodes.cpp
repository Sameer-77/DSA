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

TreeNode *createBT(int x)
{
    if (x == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(x);
    int data;
    cout << "Enter the Left Child of " << x << " (-1 if no Left Child) : ";
    cin >> data;
    root->left = createBT(data);
    cout << "Enter the Right Child of " << x << " (-1 if no Right Child) : ";
    cin >> data;
    root->right = createBT(data);
    return root;
}

TreeNode *removeHalfNodes(TreeNode *root)
{
    if (!root)
    {
        return NULL;
    }
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if (root->left && !root->right)
        return root->left;
    if (!root->left && root->right)
        return root->right;
    return root;
}

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    int data;
    cout << "Enter the root data : ";
    cin >> data;
    TreeNode *root = createBT(data);
    removeHalfNodes(root);
    cout << "After removing Half Nodes, BT is : ";
    inorder(root);
}
