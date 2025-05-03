
#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, vector<bool> &vis)
{
    if (temp.size() == arr.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int pos = 0; pos < arr.size(); pos++)
    {
        if (!vis[pos])
        {
            vis[pos] = true;
            temp.push_back(arr[pos]);
            helper(arr, temp, ans, vis);
            temp.pop_back();
            vis[pos] = false;
        }
    }
}

void permutations(vector<int> &arr, vector<vector<int>> &ans)
{
    vector<int> temp;
    vector<bool> vis(arr.size(), false);
    helper(arr, temp, ans, vis);
}

int main()
{
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans;
    permutations(arr, ans);
    cout << "Permutations are\n";
    for (auto &temp : ans)
    {
        cout << "[ ";
        for (int num : temp)
        {
            cout << num << " ";
        }
        cout << " ]\n";
    }
}
