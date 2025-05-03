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

int main()
{
    int x;
    cout << "Enter the root value : ";
    cin >> x;
    TreeNode *root = createBTree(x);
    vector<int> maxVals;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            maxi = max(maxi, node->val);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        maxVals.push_back(maxi);
    }
    cout << "----------------------MAX VALUES AT EACH LEVEL---------------------\n";
    for (int i = 0; i < maxVals.size(); i++)
    {
        cout << "Level " << i + 1 << " : " << maxVals[i] << endl;
    }
}
