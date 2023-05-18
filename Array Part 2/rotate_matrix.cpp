#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reflectY(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reflectY(matrix);
    }
};