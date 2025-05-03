
#include <bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, vector<vector<int>> &ans)
{
    if (i == arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int pos = i; pos < arr.size(); pos++)
    {
        swap(arr[i], arr[pos]);
        helper(i + 1, arr, ans);
        swap(arr[i], arr[pos]);
    }
}

void permutations(vector<int> &arr, vector<vector<int>> &ans)
{
    helper(0, arr, ans);
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
