
// Problem Link : https://leetcode.com/problems/rotate-array/description/

#include <bits/stdc++.h>
using namespace std;

void RightRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;
    vector<int> temp(k);
    // COPY LAST K ELEMENTS
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[n - k + i];
    }
    // MOVE FIRST N-K ELEMENTS TO RIGHT BY K PLACES
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    // COPY BACK ELEMENTS FROM TEMP
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int n;
    cout << "Enter Array size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before right rotation : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k;
    cout << "Enter K : ";
    cin >> k;
    RightRotate(arr, k);
    cout << "Array after right rotation : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}