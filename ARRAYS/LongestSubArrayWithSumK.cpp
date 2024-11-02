
// THIS SOLUTION WORKS ONLY FOR ARRAY HAVING POSITIVE NUMBERS

// Problem Link : https://bit.ly/3GHyBOS

#include <bits/stdc++.h>
using namespace std;

int LongestSubArray(vector<int> &arr, int k)
{
    int left = 0, right = 0, sum = arr[0];
    int maxLen = 0;
    while (right < arr.size())
    {
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < arr.size())
        {
            sum += arr[right];
        }
    }
    return maxLen;
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter K : ";
    cin >> k;
    cout << "Longest SubArray is : " << LongestSubArray(arr, k);
}