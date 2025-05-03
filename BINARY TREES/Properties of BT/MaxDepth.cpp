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

int maxDepthOfBT(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int lH = maxDepthOfBT(root->left);
    int rH = maxDepthOfBT(root->right);

    return 1 + max(lH, rH);
}

int main()
{
    int data;
    cout << "Enter the root : ";
    cin >> data;
    TreeNode *root = BT(data);
    cout << "MAX DEPTH IS : " << maxDepthOfBT(root);
}