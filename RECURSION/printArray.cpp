#include <bits/stdc++.h>
#include <vector>
using namespace std;

void printArray(int i, vector<int> &arr, int n)
{
    if (i == n)
    {
        return;
    }
    cout << arr[i] << " ";
    printArray(i + 1, arr, n);
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array elements are : ";
    printArray(0, arr, n);
}