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

void preOrder(TreeNode *root, vector<int> &pre)
{
    if (!root)
        return;
    pre.push_back(root->data);
    preOrder(root->left, pre);
    preOrder(root->right, pre);
}

void printTree(vector<int> &pre)
{
    int n = pre.size();
    for (int i = 0; i < n; i++)
    {
        cout << pre[i] << " ";
    }
}

int MaxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int left = 1 + MaxDepth(root->left);
    int right = 1 + MaxDepth(root->right);

    return max(left, right);
}

int main()
{
    TreeNode *root = BuildTree();
    vector<int> pre;
    preOrder(root, pre);
    cout << "PREORDER : ";
    printTree(pre);
    cout << endl;
    cout << "MAXIMUM DEPTH OF THE GIVEN BINARY TREE IS " << MaxDepth(root);
}