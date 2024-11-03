

// PROBLEM LINK : https://leetcode.com/problems/3sum/description/

#include <bits/stdc++.h>
using namespace std;

void ThreeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j - 1] == nums[j])
                    j++;
                while (k > j && nums[k + 1] == nums[k])
                    k--;
            }
        }
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
    ThreeSum(nums);
}

//---------------------------------------BRUTE FORCE-----------------------------------------------
/*
int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    cout << "Triplets are : ";
    for (const auto &triplet : ans)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
*/

//-------------------------------------------------BETTER APPROACH-----------------------------------------

/*
int n = nums.size();
    set<vector<int>> uniqueSet;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (st.find(third) != st.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                uniqueSet.insert(temp);
            }
            st.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(uniqueSet.begin(), uniqueSet.end());

    for (const auto &triplet : ans)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
*/