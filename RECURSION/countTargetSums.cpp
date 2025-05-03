#include <bits/stdc++.h>
using namespace std;

int findTarget(int i, vector<int> &arr, int target)
{

    if (i == arr.size())
    {
        return target == 0;
    }

    return findTarget(i + 1, arr, target - arr[i]) + findTarget(i + 1, arr, target);
}

int find(vector<int> &arr, int target)
{
    findTarget(0, arr, target);
}

int main()
{
    int n;
    cout << "Enter the array size : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target : ";
    cin >> target;
    cout << "Number of subsets having sum " << target << " : " << find(arr, target);
}