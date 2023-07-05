#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string str1 = strs[0];

        for (auto str2 : strs)
        {
            string word = "";
            int i = 0;
            while (i < min(str1.length(), str2.length()))
            {
                if (str1[i] != str2[i])
                    break;
                word += str1[i];
                i++;
            }
            str1 = word;
        }
        return str1;
    }
};