#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int, int> mp;
    int count = 0;
    int xr = 0;
    for (int n : arr)
    {
        xr = xr ^ n;
        if (xr == x)
            count++;
        count += mp[xr ^ x];
        mp[xr]++;
    }
    return count;
}