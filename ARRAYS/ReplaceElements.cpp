

// Problem Link : https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/

#include <bits/stdc++.h>
using namespace std;

void ReplaceElements(vector<int> &nums)
{
    int n = nums.size();
    int maxEl = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int currMax = nums[i];
        nums[i] = maxEl;
        maxEl = max(maxEl, currMax);
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
    ReplaceElements(nums);
    cout << "After Replacement : ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}