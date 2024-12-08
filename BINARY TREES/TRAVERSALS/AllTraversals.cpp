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
    cout << "Enter the root : ";
    cin >> data;
    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << "Enter the left child of " << curr->data << " : ";
        cin >> data;
        if (data != -1)
        {
            curr->left = new TreeNode(data);
            q.push(curr->left);
        }
        cout << "Enter the right child of " << curr->data << " : ";
        cin >> data;
        if (data != -1)
        {
            curr->right = new TreeNode(data);
            q.push(curr->right);
        }
    }
    return root;
}

void AllTraversals(TreeNode *root, vector<int> &pre, vector<int> &post, vector<int> &inorder)
{
    if (!root)
        return;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto &node = st.top();
        if (node.second == 1)
        {
            pre.push_back(node.first->data);
            node.second++;
            if (node.first->left)
            {
                st.push({node.first->left, 1});
            }
        }
        else if (node.second == 2)
        {
            inorder.push_back(node.first->data);
            node.second++;
            if (node.first->right)
            {
                st.push({node.first->right, 1});
            }
        }
        else
        {
            post.push_back(node.first->data);
            st.pop();
        }
    }
}

int main()
{
    TreeNode *root = buildTree();
    vector<int> pre, post, inorder;
    AllTraversals(root, pre, post, inorder);
    cout << "PREORDER : ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << "INORDER : ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << "POSTORDER : ";
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
}