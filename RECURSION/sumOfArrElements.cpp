#include <bits/stdc++.h>
using namespace std;

int sumOfArrayElements(int i, int arr[], int n)
{
    if (i == n)
    {
        return 0;
    }
    return arr[i] + sumOfArrayElements(i + 1, arr, n);
}

int main()
{
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Sum of array elements : " << sumOfArrayElements(0, arr, n);
}