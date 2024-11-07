
// Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

int MinimumInRotatedSortedArr(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Left half Sorted
        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        // Right half sorted
        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Minimum Element is " << MinimumInRotatedSortedArr(nums);
}