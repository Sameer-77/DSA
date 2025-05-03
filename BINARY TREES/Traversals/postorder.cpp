#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        this->val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode *createBTree(int x)
{
    if (x == -1)
    {
        return NULL;
    }
    TreeNode *node = new TreeNode(x);
    int data;
    cout << "Enter the left child of " << x << " (-1 if no child) : ";
    cin >> data;
    node->left = createBTree(data);
    cout << "Enter the right child of " << x << " (-1 if no child) : ";
    cin >> data;
    node->right = createBTree(data);
    return node;
}

void postorder(TreeNode *root, vector<int> &post)
{
    if (!root)
    {
        return;
    }
    postorder(root->left, post);
    postorder(root->right, post);
    post.push_back(root->val);
}

int main()
{
    int x;
    cout << "Enter the root value : ";
    cin >> x;
    TreeNode *root = createBTree(x);
    vector<int> post;
    postorder(root, post);
    cout << "Postorder : ";
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
}
