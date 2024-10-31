

// Problem Link : https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

int MissingNum(vector<int> &arr)
{
    int n = arr.size();
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ i + 1;
        xor2 = xor2 ^ arr[i];
    }
    return xor1 ^ xor2;
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
    cout << "MISSED NUMBER IS : " << MissingNum(arr);
}