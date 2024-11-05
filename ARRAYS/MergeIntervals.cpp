

// PROBLEM LINK : https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
using namespace std;
void MergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    cout << "Interval array After Merging : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{" << ans[i][0] << " " << ans[i][1] << "}" << " ";
    }
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter intervals : ";
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    cout << "Interval array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << "{" << intervals[i][0] << " " << intervals[i][1] << "}" << " ";
    }
    cout << endl;
    MergeIntervals(intervals);
}

//----------------------------------------BRUTE FORCE-----------------------------
/*
void MergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    cout << "Interval array After Merging : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{" << ans[i][0] << " " << ans[i][1] << "}" << " ";
    }
}
*/