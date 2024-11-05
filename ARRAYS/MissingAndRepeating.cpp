
// Problem Link : https://www.naukri.com/code360/problems/missing-and-repeating-numbers_873366?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;
pair<int, int> FindMissingAndRepeating(vector<int> nums)
{
    int n = nums.size();
    int nSum = (n * (n + 1)) / 2;
    int sum2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate the actual sum and sum of squares from the array
    long long sum = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        sum2 += (long long)nums[i] * nums[i];
    }

    // val1 = x - y and val2 = x^2 - y^2
    long long val1 = sum - nSum;
    long long val2 = sum2 - sum2N;

    // x + y = val2 / val1
    val2 = val2 / val1;

    // Calculate x and y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    // Return the pair (missing, repeating)
    return {(int)y, (int)x};
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    FindMissingAndRepeating(nums);
}

//---------------------------------------------------------BRUTE FORCE-----------------------------------------
/*
pair<int, int> FindMissingAndRepeating(vector<int> nums)
{
    int n = nums.size();
    pair<int, int> ans;
    ans.first = -1;  // Initialize missing number to -1
    ans.second = -1; // Initialize repeating number to -1

    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        int num = i; // Use 'i' as the number to check
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == num)
                count++;
        }
        if (count == 0)
            ans.first = num; // Missing number
        if (count == 2)
            ans.second = num; // Repeating number
    }
    return ans; // Return the pair
}
*/