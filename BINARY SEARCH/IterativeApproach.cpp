#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (nums[mid] > target)
        {
            h = mid - 1;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            return mid;
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
    int target;
    cout << "Enter the target element : ";
    cin >> target;

    cout << "Position of Target Element is : " << BinarySearch(nums, target);
}