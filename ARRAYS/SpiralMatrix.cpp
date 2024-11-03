

// Problem Link : https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int rowBegin = 0, colBegin = 0;
    int rowEnd = m - 1, colEnd = n - 1;
    while (rowBegin <= rowEnd && colBegin <= colEnd)
    {

        // Left To Right
        for (int i = colBegin; i <= colEnd; i++)
        {
            ans.push_back(matrix[rowBegin][i]);
        }
        rowBegin++;

        // Up To Down
        for (int i = rowBegin; i <= rowEnd; i++)
        {
            ans.push_back(matrix[i][colEnd]);
        }
        colEnd--;

        // Right to Left
        if (rowBegin <= rowEnd)
        {
            for (int i = colEnd; i >= colBegin; i--)
            {
                ans.push_back(matrix[rowEnd][i]);
            }
        }
        rowEnd--;

        // Down To Up
        if (colBegin <= colEnd)
        {
            for (int i = rowEnd; i >= rowBegin; i--)
            {
                ans.push_back(matrix[i][colBegin]);
            }
        }
        colBegin++;
    }

    cout << "SPIRAL ORDER : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int m, n;
    cout << "Enter num of Rows : ";
    cin >> m;
    cout << "Enter num of Cols : ";
    cin >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    spiralMatrix(matrix);
}