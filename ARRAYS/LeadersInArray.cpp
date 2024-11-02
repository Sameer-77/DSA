#include <bits/stdc++.h>
using namespace std;

void Leaders(vector<int> &nums)
{
    int n = nums.size();
    int maxEl = nums[n - 1];
    vector<int> ans;
    ans.push_back(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] >= maxEl)
        {
            ans.push_back(nums[i]);
        }
        maxEl = max(maxEl, nums[i]);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Original array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Leaders of an Array : ";
    Leaders(nums);
}