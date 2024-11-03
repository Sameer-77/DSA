

// Problem Link : https://leetcode.com/problems/majority-element-ii/description/

// Observation : Maximum 2 elements can be present at any given length that appear floor(N/3) times....

#include <bits/stdc++.h>
using namespace std;

void MajorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count1 = 0, count2 = 0;
    int element1, element2;
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && nums[i] != element2)
        {
            element1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0 && nums[i] != element1)
        {
            element2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element1)
        {
            count1++;
        }
        else if (nums[i] == element2)
        {
            count2++;
        }
    }
    vector<int> ans;
    if (count1 > n / 3)
        ans.push_back(element1);
    if (count2 > n / 3)
        ans.push_back(element2);
    cout << "Elements are : ";
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
    MajorityElement(nums);
}