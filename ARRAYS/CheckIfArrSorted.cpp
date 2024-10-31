#include <bits/stdc++.h>
using namespace std;

string ArraySorted(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return "NOT SORTED";
        }
    }
    return "SORTED";
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
    cout << "Is the array Sorted : " << ArraySorted(arr);
}