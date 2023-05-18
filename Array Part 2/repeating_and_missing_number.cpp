#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i] ^ (i + 1);
    }

    int setBit = xr & ~(xr - 1);

    int xr1 = 0, xr2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setBit)
            xr1 = xr1 ^ arr[i];
        else
            xr2 = xr2 ^ arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & setBit)
            xr1 = xr1 ^ i;
        else
            xr2 = xr2 ^ i;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (xr1 == arr[i])
            cnt++;

    if (cnt == 2)
        return {xr2, xr1};
    else
        return {xr1, xr2};
}