

// Problem Link : https://www.naukri.com/code360/problems/sorted-array_6613259

#include <bits/stdc++.h>
using namespace std;

void UnionOfArr(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int m = a.size(), n = b.size();
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else if (b[j] < a[i])
        {
            if (ans.empty() || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
        else
        {
            if (ans.empty() || a[i] != ans.back())
            {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (ans.empty() || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < n)
    {
        if (ans.empty() || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    cout << "Union Array : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n1;
    cout << "Enter array-1 size : ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter array-1 elements : ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    int n2;
    cout << "Enter array-2 size : ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter array-2 elements : ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    UnionOfArr(arr1, arr2);
}