

// Problem Link : https://leetcode.com/problems/single-number/description/

// Optimal Approach : BINARY SEARCH

#include <bits/stdc++.h>
using namespace std;

int SingleElement(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Single Element is : " << SingleElement(arr);
}