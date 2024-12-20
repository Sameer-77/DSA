
// Problem Link : https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

void NextPermutation(vector<int> &nums)
{
    int ind = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
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
    NextPermutation(nums);
    cout << "Next Permutation is : ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}