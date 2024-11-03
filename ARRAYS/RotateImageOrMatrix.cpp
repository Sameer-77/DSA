
// Problem Link : https://leetcode.com/problems/rotate-image/description/

#include <bits/stdc++.h>
using namespace std;

void RotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    int n;
    cout << "Enter num of Rows and Cols : ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter Matrix Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Original Matrix is " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix after Rotation to 90 degrees " << endl;
    RotateMatrix(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//-------------------------------------------BRUTE FORCE----------------------------------------------------
/*
void RotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = ans;
}
*/