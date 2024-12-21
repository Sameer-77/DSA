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

void TopView(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    queue<pair<TreeNode *, int>> q; // Store Node, Vertical
    map<int, int> mpp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto &x = q.front();
        q.pop();
        TreeNode *node = x.first;
        int vertical = x.second;
        if (mpp.find(vertical) == mpp.end())
        {
            mpp[vertical] = node->data;
        }
        if (node->left)
            q.push({node->left, vertical - 1});
        if (node->right)
            q.push({node->right, vertical + 1});
    }

    for (auto &it : mpp)
    {
        ans.push_back(it.second);
    }
}

int main()
{
    TreeNode *root = BuildTree();
    vector<int> ans;
    TopView(root, ans);
    cout << "Top View : " << " ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
