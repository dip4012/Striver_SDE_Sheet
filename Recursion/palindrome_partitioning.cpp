#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
    void makePartitiion(string s, vector<vector<string>> &ans, vector<string> &cur, int index, int n)
    {
        if (index == n)
        {
            ans.push_back(cur);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (isPalindrome(s, index, i))
            {
                cur.push_back(s.substr(index, i - index + 1));
                makePartitiion(s, ans, cur, i + 1, n);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> cur;
        vector<vector<string>> ans;
        makePartitiion(s, ans, cur, 0, s.length());
        return ans;
    }
};