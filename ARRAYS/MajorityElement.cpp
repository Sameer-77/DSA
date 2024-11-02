

// Problem Link : https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

// MOORE'S VOTING ALGORITHM

int MajorityElement(vector<int> &arr)
{
    int element;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            element = arr[i];
            count = 1;
        }
        else if (arr[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return element;
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Majority element is : " << MajorityElement(arr);
}