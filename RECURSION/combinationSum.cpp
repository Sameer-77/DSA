
#include <bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0 || i == arr.size())
    {
        return;
    }
    temp.push_back(arr[i]);
    helper(i, arr, ans, temp, target - arr[i]);
    temp.pop_back();
    helper(i + 1, arr, ans, temp, target);
}

void combinationSum(vector<int> &arr, vector<vector<int>> &ans, int target)
{
    vector<int> temp;
    helper(0, arr, ans, temp, target);
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
    int target;
    cout << "Enter the target : ";
    cin >> target;
    combinationSum(arr, ans, target);
    cout << "Combinations havig sum " << target << " are\n";
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
