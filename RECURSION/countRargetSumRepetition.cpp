#include <bits/stdc++.h>
using namespace std;

int findTarget(int i, vector<int> &arr, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (i == arr.size() || target < 0)
    {
        return 0;
    }

    return findTarget(i + 1, arr, target) + findTarget(i, arr, target - arr[i]);
}

int find(vector<int> &arr, int target)
{
    return findTarget(0, arr, target); // Return the count
}

int main()
{
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    cout << "Number of subsets having sum " << target << " : " << find(arr, target) << endl;

    return 0;
}
