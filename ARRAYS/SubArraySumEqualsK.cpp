
// Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <bits/stdc++.h>
using namespace std;

int countSubArrays(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int count = 0;
    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefSum += nums[i];
        if (mpp.find(prefSum - k) != mpp.end())
        {
            count += mpp[prefSum - k];
        }
        mpp[prefSum]++;
    }
    return count;
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
    int k;
    cout << "Enter K value : ";
    cin >> k;
    cout << "Number of Subarrays with sum equals K : " << countSubArrays(nums, k);
}