

// Problem Link : https://www.naukri.com/code360/problems/rotate-array_1230543?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;
void LeftRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;
    vector<int> temp(k);
    // COPY FIRST K ELEMENTS TO TEMP
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    // MOVE ELEMENTS FROM Kth INDEX TOWARDS FIRST
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    // COPY ELEMENTS FROM TEMP TO ARR
    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }
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
    int k;
    cout << "Enter K value : ";
    cin >> k;
    cout << "Original array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    LeftRotate(arr, k);
    cout << "After Rotation by K places : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}