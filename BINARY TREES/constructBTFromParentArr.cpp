#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *createBT(int x)
{
    if (x == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(x);
    int data;
    cout << "Enter the Left Child of " << x << " (-1 if no Left Child) : ";
    cin >> data;
    root->left = createBT(data);
    cout << "Enter the Right Child of " << x << " (-1 if no Right Child) : ";
    cin >> data;
    root->right = createBT(data);
    return root;
}

TreeNode *removeHalfNodes(TreeNode *root)
{
    if (!root)
    {
        return NULL;
    }
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if (root->left && !root->right)
        return root->left;
    if (!root->left && root->right)
        return root->right;
    return root;
}
TreeNode *constructBT(vector<int> &parentArr)
{
    int n = parentArr.size();
    vector<TreeNode *> parentChild(n, NULL);
    for (int i = 0; i < n; i++)
    {
        parentChild[i] = new TreeNode(i);
    }
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (parentArr[i] == -1)
        {
            root = parentChild[i];
            continue;
        }
        TreeNode *par = parentChild[parentArr[i]];
        if (!par->left)
        {
            par->left = parentChild[i];
        }
        else
        {
            par->right = parentChild[i];
        }
    }
    return root;
}

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of Nodes of BT : ";
    cin >> n;
    vector<int> parentArr(n, 0);
    cout << "Enter the parents of each node : ";
    for (int i = 0; i < n; i++)
    {
        cin >> parentArr[i];
    }
    TreeNode *root = constructBT(parentArr);
    cout << "Level Order of BT is : ";
    inorder(root);
}
