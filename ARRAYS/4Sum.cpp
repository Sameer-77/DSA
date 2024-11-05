

// PROBLEM LINK : https://leetcode.com/problems/4sum/description/

#include <bits/stdc++.h>
using namespace std;
void FourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k - 1] == nums[k])
                        k++;
                    while (k < l && nums[l + 1] == nums[l])
                        l--;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
    cout << "Result : " << endl;
    for (const auto &it : ans)
    {
        for (int num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target : ";
    cin >> target;
    FourSum(nums, target);
}

//-------------------------------------------------BRUTE FORCE------------------------------------ TC = O(N^4)

/*
int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
*/