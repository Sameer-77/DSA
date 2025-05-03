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

int findLeftHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int leftHeight = 0;
    while (root)
    {
        leftHeight++;
        root = root->left;
    }
    return leftHeight;
}

int findRightHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int rightHeight = 0;
    while (root)
    {
        rightHeight++;
        root = root->right;
    }
    return rightHeight;
}

int countCompleteBTNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int lH = findLeftHeight(root);
    int rH = findRightHeight(root);
    if (lH == rH)
    {
        return (1 << lH) - 1;
    }
    return 1 + countCompleteBTNodes(root->left) + countCompleteBTNodes(root->right);
}

int main()
{
    int data;
    cout << "Enter the root data : ";
    cin >> data;
    TreeNode *root = createBT(data);
    cout << "Number of Nodes : " << countCompleteBTNodes(root);
}

//------------------------------TC O(n) ---------------------------------------------------------------------------

/*int countCompleteBTNodes(TreeNode *root)

{
    if (!root)
    {
       return 0;
    }
   return 1 + countCompleteBTNodes(root->left) + countCompleteBTNodes(root->right);
 }

 */