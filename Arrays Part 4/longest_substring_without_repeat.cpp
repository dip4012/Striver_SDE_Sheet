#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mp(256, -1);
        int maxLen = 0;
        int left, right;
        left = right = 0;
        while (right < s.size())
        {
            if (mp[s[right]] != -1)
                left = max(left, mp[s[right]] + 1);
            mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};