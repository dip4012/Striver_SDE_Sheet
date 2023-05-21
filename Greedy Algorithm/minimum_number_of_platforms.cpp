#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    int platform_count[2360] = {0};
    for (int i = 0; i < n; i++)
    {
        platform_count[at[i]]++;
        platform_count[dt[i] + 1]--;
    }
    int platform = platform_count[0];
    for (int i = 1; i < 2360; i++)
    {
        platform_count[i] = platform_count[i - 1] + platform_count[i];
        platform = max(platform, platform_count[i]);
    }
    return platform;
}