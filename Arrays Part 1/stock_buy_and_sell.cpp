#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy, sell, profit = 0;
        buy = sell = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < buy)
                buy = sell = prices[i];
            if (prices[i] > sell)
                sell = prices[i];
            profit = max(profit, sell - buy);
        }
        return profit;
    }
};