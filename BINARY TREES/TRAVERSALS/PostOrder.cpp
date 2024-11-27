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

void PostOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    TreeNode *root = buildTree();
    PostOrder(root);
}