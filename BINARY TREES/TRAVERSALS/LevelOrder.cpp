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
    // if (data == -1)
    // {
    //     return;
    // }

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

void LevelOrderTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        cout << "Empty tree....";
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int numOfNodes = q.size();
        vector<int> v;
        for (int i = 0; i < numOfNodes; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            v.push_back(node->data);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(v);
    }

    // Printing Level order Traversal
    int i = 0;
    for (vector<int> v : ans)
    {
        cout << "LEVEL " << i << "->";
        for (int val : v)
        {
            cout << val << " ";
        }
        i++;
        cout << endl;
    }
}

int main()
{
    TreeNode *root = buildTree();
    LevelOrderTraversal(root);
}