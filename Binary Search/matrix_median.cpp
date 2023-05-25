#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int k = (n * m + 1) / 2;
    int lo = 1, hi = 100000;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;

        int count = 0;
        for (int i = 0; i < n; i++)
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

        if (count < k)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}