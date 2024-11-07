#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &nums, int target, int l, int h)
{
    // Check if l and h are within bounds
    if (l < 0 || h >= nums.size())
        return -1;

    // Base case: if the range is invalid
    if (l > h)
        return -1;

    int mid = (l + h) / 2;

    // Check if the middle element is the target
    if (nums[mid] == target)
        return mid;
    // Recursive case: search in the left half
    else if (nums[mid] > target)
        return BinarySearch(nums, target, l, mid - 1);
    // Recursive case: search in the right half
    else
        return BinarySearch(nums, target, mid + 1, h);
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

    cout << "Position of Target Element is : " << BinarySearch(nums, target, 0, n - 1);
}