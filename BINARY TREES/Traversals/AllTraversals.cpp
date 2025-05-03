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

void AllTraversals(TreeNode *root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    if (!root)
    {
        return;
    }
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto &it = st.top();
        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;
            if (it.first->left)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            it.second++;
            in.push_back(it.first->val);

            if (it.first->right)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->val);
            st.pop();
        }
    }
}

int main()
{
    int data;
    cout << "Enter the root : ";
    cin >> data;
    TreeNode *root = BT(data);
    vector<int> pre, post, in;
    AllTraversals(root, pre, in, post);
    cout << "\nPreOrder : ";
    for (int num : pre)
    {
        cout << num << " ";
    }
    cout << "\nInorder : ";
    for (int num : in)
    {
        cout << num << " ";
    }
    cout << "\nPostOrder : ";
    for (int num : post)
    {
        cout << num << " ";
    }
}