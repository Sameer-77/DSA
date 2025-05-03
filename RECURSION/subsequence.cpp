#include <bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
{
    if (i == arr.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    helper(i + 1, arr, temp, ans);
    temp.pop_back();
    helper(i + 1, arr, temp, ans);
}

vector<vector<int>> subsequence(vector<int> &arr)
{
    vector<int> temp;
    vector<vector<int>> ans;
    helper(0, arr, temp, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = subsequence(arr);
    cout << "Subsequence" << endl;
    for (auto temp : ans)
    {
        cout << "[ ";
        for (int num : temp)
        {
            cout << num << " ";
        }
        cout << " ]" << endl;
    }
}
