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

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (root->left)
    {
        printTree(root->left);
    }
    if (root->right)
    {
        printTree(root->right);
    }
}

TreeNode *BuildTree()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }

    TreeNode *temp = new TreeNode(x);
    // Go left
    cout << "Enter the Left Child of " << x << " (-1 is no left child) : ";
    temp->left = BuildTree();
    // Go right;
    cout << "Enter the Right Child of " << x << " (-1 is no right child) : ";
    temp->right = BuildTree();

    return temp;
}

int main()
{
    cout << "Enter the root Node : ";
    TreeNode *root;
    root = BuildTree();
    printTree(root);
}