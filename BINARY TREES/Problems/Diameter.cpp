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
    int data;
    cout << "Enter the root Node: ";
    cin >> data;

    if (data == -1)
    {
        cout << "Empty Tree.." << endl;
        return NULL;
    }

    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Input for the left child
        cout << "Enter the left child of " << curr->data << ": ";
        cin >> data;
        if (data != -1)
        {
            curr->left = new TreeNode(data);
            q.push(curr->left);
        }

        // Input for the right child
        cout << "Enter the right child of " << curr->data << ": ";
        cin >> data;
        if (data != -1)
        {
            curr->right = new TreeNode(data);
            q.push(curr->right);
        }
    }

    return root;
}

int findMax(TreeNode *root, int &maxi)
{
    if (!root)
        return 0;
    int l = findMax(root->left, maxi);
    int r = findMax(root->right, maxi);
    maxi = max(maxi, l + r);

    return 1 + max(l, r);
}
int diameter(TreeNode *root)
{
    if (!root)
        return 0;
    int maxi = 0;
    findMax(root, maxi);
    return maxi;
}

int main()
{
    TreeNode *root = BuildTree();
    cout << "DIAMETER OF THE GIVEN BINARY TREE IS " << diameter(root);
}

/*
int findHeight(TreeNode *root)
{
    if (!root)
        return 0;
    int lH = findHeight(root->left);
    int rH = findHeight(root->right);
    return 1 + max(lH, rH);
}
int diameter(TreeNode *root)
{
    if (!root)
        return 0;
    int lH = findHeight(root->left);
    int rH = findHeight(root->right);
    int rootDiameter = lH + rH;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(rootDiameter, max(leftDiameter, rightDiameter));
}
*/