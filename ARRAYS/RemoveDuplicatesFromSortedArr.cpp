#include <bits/stdc++.h>
using namespace std;

void RemoveDuplicates(vector<int> &arr, int &unique)
{
    int i = 0, j = 0;
    while (j < arr.size())
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
            unique++;
        }
        j++;
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
    int unique = 1;
    RemoveDuplicates(arr, unique);
    for (int i = 0; i < unique; i++)
    {
        cout << arr[i] << " ";
    }
}