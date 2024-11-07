#include <bits/stdc++.h>
using namespace std;

int UpperBound(vector<int> &nums, int target)
{
    int upperBound = -1;
    int l = 0, h = nums.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (nums[mid] > target)
        {
            upperBound = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return upperBound;
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

    cout << "Upper Bound Position of Target Element is : " << UpperBound(nums, target);
}