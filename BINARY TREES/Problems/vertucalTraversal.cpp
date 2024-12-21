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

void verticalOrderTraversal(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> mp;
    while (!q.empty())
    {
        auto qFront = q.front();
        q.pop();
        TreeNode *node = qFront.first;
        int vertical = qFront.second.first;
        int level = qFront.second.second;
        mp[vertical][level].insert(node->data);

        if (node->left)
            q.push({node->left, {vertical - 1, level + 1}});
        if (node->right)
            q.push({node->right, {vertical + 1, level + 1}});
    }

    for (auto &verticalPair : mp)
    {                                       // Iterate over map
        int vertical = verticalPair.first;  // Vertical levels
        auto &levels = verticalPair.second; // map of values

        for (auto &levelPair : levels)
        {                                   // Iterate over levels within the vertical
            int v = levelPair.first;        // The key(level index)
            auto &nodes = levelPair.second; // The value (multiset val)

            for (int val : nodes)
            {
                ans.push_back(val);
            }
        }
    }
}

int main()
{
    TreeNode *root = BuildTree();
    vector<int> ans;
    verticalOrderTraversal(root, ans);
    cout << "Vertical order traversal : " << " ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
