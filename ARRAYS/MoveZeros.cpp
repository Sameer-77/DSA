

// Problem Link : https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

void MoveZeros(vector<int> &arr)
{
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        return;
    }
    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
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
    cout << "Original Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    MoveZeros(arr);
    cout << "Array after moving Zeros : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}