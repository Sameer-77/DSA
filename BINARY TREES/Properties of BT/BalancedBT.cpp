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
    cout << "Enter the Left Child of " << x << "(-1 if no Left Child) : ";
    cin >> data;
    root->left = BT(data);
    cout << "Enter the Right Child of " << x << " (-1 if no Right Child) : ";
    cin >> data;
    root->right = BT(data);
    return root;
}

int findHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int lH = findHeight(root->left);
    int rH = findHeight(root->right);
    if (abs(lH - rH) > 1)
    {
        return -1;
    }
    if (lH == -1 || rH == -1)
    {
        return -1;
    }
    return 1 + max(lH, rH);
}

bool isBalanced(TreeNode *root)
{
    return findHeight(root) != -1;
}

int main()
{
    int data;
    cout << "Enter the root : ";
    cin >> data;
    TreeNode *root = BT(data);
    cout << "IS BALANCED : " << isBalanced(root) ? "YES" : "NO";
}