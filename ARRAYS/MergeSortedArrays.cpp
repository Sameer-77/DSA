

// Problem Link : https://leetcode.com/problems/merge-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;
void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2)
{
    if (nums1[ind1] > nums2[ind2])
        swap(nums1[ind1], nums2[ind2]);
}
void MergeTwoSortedArrays(vector<int> &nums1, vector<int> &nums2, int m, int n)
{
    int len = m + n;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0, right = left + gap;
        while (right < len)
        {
            // Comparing within nums1
            if (left < m && right < m)
            {
                swapIfGreater(nums1, nums1, left, right);
            }
            // Comparing within nums2
            else if (left >= m)
            {
                swapIfGreater(nums2, nums2, left - m, right - m);
            }
            // Comparing between two arrays
            else
            {
                swapIfGreater(nums1, nums2, left, right - m);
            }
            right++;
            left++;
        }
        if (gap == 1)
            break;
        else
            gap = (gap / 2) + gap % 2;
    }
    copy(nums2.begin(), nums2.end(), nums1.begin() + m);
}
int main()
{
    int m, n;
    cout << "Enter array-1 size : ";
    cin >> m;
    cout << "Enter array-2 size : ";
    cin >> n;
    vector<int> nums1(m), nums2(n);
    cout << "Enter array-1 elements in a sorted order : ";
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }
    cout << "Enter array-2 elements in a sorted order : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    MergeTwoSortedArrays(nums1, nums2, m, n);
    cout << "After Merging : ";
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
}

//----------------------------------------------BRUTE FORCE--------------------------------------------------
/*
void MergeTwoSortedArrays(vector<int> &nums1, vector<int> &nums2, int m, int n)
{
    vector<int> ans(m + n);
    int left = 0, right = 0, ind = 0;
    while (left < m && right < n)
    {
        if (nums1[left] <= nums2[right])
        {
            ans[ind++] = nums1[left++];
        }
        else
        {
            ans[ind++] = nums2[right++];
        }
    }
    while (left < m)
    {
        ans[ind++] = nums1[left++];
    }
    while (right < n)
    {
        ans[ind++] = nums2[right++];
    }
}
*/

//-----------------------------------------OPTIMAL-1---------------------------------------------------
/*
void MergeTwoSortedArrays(vector<int> &nums1, vector<int> &nums2, int m, int n)
{
    int left = m - 1, right = 0;
    while (left >= 0 && right < n)
    {
        if (nums1[left] > nums2[right])
        {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.begin() + n);
    copy(nums2.begin(), nums2.end(), nums1.begin() + m);
}
*/