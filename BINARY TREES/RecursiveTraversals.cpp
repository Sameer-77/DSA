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

TreeNode *BuildTree()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    TreeNode *temp = new TreeNode(x);

    // Go left
    cout << "Enter the Left Child of " << x << " (-1 if no left child) : ";
    temp->left = BuildTree();

    // Go right
    cout << "Enter the Right child of " << x << " (-1 if no right child) : ";
    temp->right = BuildTree();

    return temp;
}

void PreOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    if (root->left)
        PreOrder(root->left);
    if (root->right)
        PreOrder(root->right);
}

void InOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    if (root->left)
        InOrder(root->left);
    cout << root->data << " ";
    if (root->right)
        InOrder(root->right);
}

void PostOrder(TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
        PostOrder(root->left);
    if (root->right)
        PostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    cout << "Enter the Root Node : ";
    TreeNode *root;
    root = BuildTree();
    cout << "PRE-ORDER TRAVERSAL : ";
    PreOrder(root);
    cout << endl;
    cout << "IN-ORDER TRAVERSAL : ";
    InOrder(root);
    cout << endl;
    cout << "POST-ORDER TRAVERSAL : ";
    PostOrder(root);
}