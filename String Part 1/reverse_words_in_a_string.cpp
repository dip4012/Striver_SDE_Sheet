#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.length();
        string ans = "", word = "";
        for (int i = 0; i < len; i++)
        {
            char ch = s[i];

            if (ch == ' ')
            {
                if (word == "")
                    continue;

                ans = " " + word + ans;
                word = "";
            }
            else
            {
                word += ch;
            }
        }
        ans = word + ans;
        if (ans[0] == ' ')
            ans = ans.substr(1);
        return ans;
    }
};