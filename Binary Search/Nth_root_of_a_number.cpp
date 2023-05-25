#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int lo = 1, hi = m;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        long long x = 1;
        for (int i = 1; i <= n; i++)
        {
            x *= mid;
            if (x > 1ll * m)
                break;
        }

        if (x == 1ll * m)
            return mid;
        else if (x < m)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}