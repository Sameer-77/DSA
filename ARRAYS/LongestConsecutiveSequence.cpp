
// Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <bits/stdc++.h>
using namespace std;

int LongestConsecutiveSequence(vector<int> &nums)
{
    unordered_set<int> st;
    int longest = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                count++;
                x = x + 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
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
    cout << "Longest consecutive Sequence : " << LongestConsecutiveSequence(nums);
}

//----------------------------------------------- BRUTE FORCE-----------------------------------------
/*
bool search(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
            return true;
    }
    return false;
}

int LongestConsecutiveSequence(vector<int> &nums)
{
    int longest = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int el = nums[i];
        int count = 1;
        while (search(nums, el + 1))
        {
            count++;
            el = el + 1;
        }
        longest = max(longest, count);
    }
    return longest;
}

*/

//------------------------------BETTER-----------------------------------------------------------
/*
int LongestConsecutiveSequence(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int longest = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == lastSmaller)
        {
            count++;
            lastSmaller = nums[i];
        }
        else if (lastSmaller != nums[i])
        {
            count = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, count);
    }
    return longest;
}
*/