#include <bits/stdc++.h>
using namespace std;

int LowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int lowerBound = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            lowerBound = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lowerBound;
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
    int target;
    cout << "Enter the target element : ";
    cin >> target;

    cout << "Lower Bound Position of Target Element is : " << LowerBound(nums, target);
}