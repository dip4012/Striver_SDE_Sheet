#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    sort(items.begin(), items.end(), [](pair<int, int> item1, pair<int, int> item2) -> bool
         { return item1.second * 1.0 / item1.first > item2.second * 1.0 / item2.first; });

    double value = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= w)
        {
            value += items[i].second;
            w -= items[i].first;
        }
        else
        {
            value += items[i].second * 1.0 / items[i].first * w;
            break;
        }
    }

    return value;
}