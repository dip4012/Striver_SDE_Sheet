#include <bits/stdc++.h>
using namespace std;

bool canPlacePlayer(vector<int> positions, int n, int c, int minSep)
{
    int count = 1, lastPos = positions[0];
    for (int i = 0; i < n; i++)
    {
        if (positions[i] - lastPos >= minSep)
        {
            count++;
            lastPos = positions[i];
        }
        if (count == c)
            return true;
    }
    return false;
}

int chessTournament(vector<int> positions, int n, int c)
{
    sort(positions.begin(), positions.end());
    int lo = 1, hi = positions[n - 1] - positions[0];
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (canPlacePlayer(positions, n, c, mid))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return hi;
}