#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(vector<int> &arr)
{
    int firstLargest = arr[0];
    int secondLargest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
    }
    return secondLargest;
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
    cout << "Second Largest Element is " << findSecondLargest(arr);
}