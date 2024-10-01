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
    int x;
    cin >> x;
    if (x == -1)
        return NULL;

    TreeNode *temp = new TreeNode(x);

    // Go left
    cout << "Enter the Left Child of " << x << " (-1 if no left child) : ";
    temp->left = BuildTree();

    // Go right
    cout << "Enter the Right child of " << x << " (-1 if no right child) : ";
    temp->right = BuildTree();

    return temp;
}

void PreOrder(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
}

void PostOrder(TreeNode *root)
{
    TreeNode *curr = root;
    stack<TreeNode *> st;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
}

void InOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main()
{
    cout << "Enter the Root Node : ";
    TreeNode *root;
    root = BuildTree();
    cout << "PRE-ORDER TRAVERSAL : ";
    PreOrder(root);
    cout << endl;
    cout << "IN-ORDER TRAVERSAL : ";
    InOrder(root);
    cout << endl;
    cout << "POST-ORDER TRAVERSAL : ";
    PostOrder(root);
}