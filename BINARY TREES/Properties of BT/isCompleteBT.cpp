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

bool isCompleteBT(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool seenNull = false;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (!temp)
        {
            seenNull = true;
        }
        else
        {
            if (seenNull)
            {
                return false;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return true;
}
int main()
{
    int data;
    cout << "Enter the root data : ";
    cin >> data;
    TreeNode *root = createBT(data);
    cout << "Is Complete Binary Tree : " << (isCompleteBT(root) ? "Yes" : "No");
}
