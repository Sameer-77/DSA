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

bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addRightBoundary(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    TreeNode *curr = root->right;
    stack<int> st;
    while (curr)
    {
        if (!isLeaf(curr))
            st.push(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
void addLeaf(TreeNode *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaf(root->left, ans);
    if (root->right)
        addLeaf(root->right, ans);
}

void boundaryTraversal(TreeNode *root)
{
    if (!root)
        return;
    vector<int> ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeaf(root, ans);
    addRightBoundary(root, ans);
    cout << "Boundary Traversal : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    TreeNode *root = BuildTree();
    boundaryTraversal(root);
}
