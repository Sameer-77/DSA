
#include <bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int target)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (i == arr.size() || target < 0)
    {
        return;
    }
    temp.push_back(arr[i]);
    helper(i + 1, arr, temp, ans, target - arr[i]);
    temp.pop_back();
    while (i + 1 < arr.size() && arr[i] == arr[i + 1])
    {
        i++;
    }
    helper(i + 1, arr, temp, ans, target);
}

void combinationSum(vector<int> &arr, vector<vector<int>> &ans, int target)
{
    vector<int> temp;
    sort(arr.begin(), arr.end());
    helper(0, arr, temp, ans, target);
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
