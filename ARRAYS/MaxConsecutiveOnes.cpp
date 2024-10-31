

// Problem Link : https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;
int MaxConsecutiveOnes(vector<int> &arr)
{
    int count = 0, maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count += 1;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
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
    cout << "MAximum consecutive Ones : " << MaxConsecutiveOnes(arr);
}