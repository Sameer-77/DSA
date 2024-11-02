

// Problem Link : https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// KADANE'S ALGORITHM

int maxSubArraySum(vector<int> &nums)
{
    int sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
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
    cout << "MAx Sum is : " << maxSubArraySum(nums);
}