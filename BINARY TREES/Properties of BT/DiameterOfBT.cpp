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

TreeNode *BT(int x)
{
    if (x == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(x);
    int data;
    cout << "Enter the Left Child of " << x << "(-1 if no Left Child) : ";
    cin >> data;
    root->left = BT(data);
    cout << "Enter the Right Child of " << x << " (-1 if no Right Child) : ";
    cin >> data;
    root->right = BT(data);
    return root;
}

int findHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int DiameterOfBT(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int lH = findHeight(root);
    int rH = findHeight(root);
    return max(lH + rH, max(DiameterOfBT(root->left), DiameterOfBT(root->right)));
}

int main()
{
    int data;
    cout << "Enter the root : ";
    cin >> data;
    TreeNode *root = BT(data);
    cout << "Diameter of BINARY TREE is " << DiameterOfBT(root);
}

// int Diameter(TreeNode *root, int &maxi)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     int lH = Diameter(root->left, maxi);
//     int rH = Diameter(root->right, maxi);

//     maxi = max(maxi, rH + lH);
//     return 1 + max(rH, lH);
// }

// int DiameterOfBT(TreeNode *root)
// {
//     if (!root)
//         return 0;
//     int maxi = 0;
//     return Diameter(root, maxi);
// }