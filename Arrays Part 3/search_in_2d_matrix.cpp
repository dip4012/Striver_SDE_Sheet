#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m * n - 1;
        while (l <= r)
        {
            int k = (l + r) / 2;

            if (matrix[k / n][k % n] == target)
                return true;
            else if (matrix[k / n][k % n] < target)
                l = k + 1;
            else
                r = k - 1;
        }

        return false;
    }
};