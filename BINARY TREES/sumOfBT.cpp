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

void sumOfBT(TreeNode *root, int &sum)
{
    if (!root)
    {
        return;
    }
    sum += root->val;
    sumOfBT(root->left, sum);
    sumOfBT(root->right, sum);
}

int main()
{
    int x;
    cout << "Enter the root value : ";
    cin >> x;
    TreeNode *root = createBTree(x);
    int sum = 0;
    sumOfBT(root, sum);
    cout << "Sum of BT : " << sum;
}
