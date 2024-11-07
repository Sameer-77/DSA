#include <bits/stdc++.h>
using namespace std;

void FirstAndLastOccurence(vector<int> &nums, int target)
{
    int first = -1;
    int l = 0, h = nums.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            h = mid - 1;
        }
        else if (nums[mid] > target)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (first == -1)
    {

        return;
    }

    int last = -1;
    l = 0, h = nums.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            l = mid + 1;
        }
        else if (nums[mid] > target)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "First Occurence is at : " << first << " and Second Occurence is at : " << last;
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
    int target;
    cout << "Enter the number whose first and last occurence has to be found : ";
    cin >> target;
    FirstAndLastOccurence(nums, target);
}