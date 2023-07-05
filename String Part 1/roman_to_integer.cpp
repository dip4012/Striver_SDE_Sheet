#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        int curMax = INT_MIN;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (values[ch] < curMax)
                ans -= values[ch];
            else
                ans += values[ch];
            curMax = max(curMax, values[ch]);
        }
        return ans;
    }
};