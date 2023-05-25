#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> time, int m, int n, long long k)
{
    long long count = 0, allotTime = 0;
    for (int i = 0; i < m; i++)
    {
        if (allotTime + time[i] > k)
        {
            count++;
            allotTime = time[i];
            if (allotTime > k)
                return false;
        }
        else
            allotTime += time[i];
    }
    if (count < n)
        return true;
    else
        return false;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long lo = time[0], hi = 0;
    for (int i = 0; i < m; i++)
    {
        lo = min(lo, 1ll * time[i]);
        hi = hi + time[i];
    }

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (isPossible(time, m, n, mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    return lo;
}