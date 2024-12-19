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

TreeNode *buildTree()
{
    int data;
    cout << "Enter the root value : ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << "Enter the Left Child of " << curr->data << " : ";
        cin >> data;
        if (data != -1)
        {
            curr->left = new TreeNode(data);
            q.push(curr->left);
        }
        cout << "Enter the Right Child of " << curr->data << " : ";
        cin >> data;
        if (data != -1)
        {
            curr->right = new TreeNode(data);
            q.push(curr->right);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = buildTree();
}

// ------------------------------------Approach-1---------------------------------------------------

/*
int findLH(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + findLH(root->left);
}
int findRH(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + findRH(root->right);
}
bool BalancedBT(TreeNode *root)
{
    if (!root)
        return true;
    int lH = findLH(root);
    int rH = findRH(root);
    if (abs(lH - rH) > 1)
        return false;

    bool l = BalancedBT(root->left);
    bool r = BalancedBT(root->right);
    return r && l;
}

*/