#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int expand(string s, int i, int j)
    {
        int left = i, right = j;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s)
    {
        int l = 0, r = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int len = expand(s, i, i);
            if (len > r - l + 1)
            {
                l = i - len / 2;
                r = i + len / 2;
            }

            len = expand(s, i, i + 1);
            if (len > r - l + 1)
            {
                l = i - len / 2 - 1;
                r = i + 1 + len / 2 - 1;
            }
        }

        return s.substr(l, r + 1);
    }
};