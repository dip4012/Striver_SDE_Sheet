#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rabinKarp(string source, string target)
    {
        if (source == "" || target == "")
            return -1;

        int n = source.length(), m = target.length();

        int BASE = 1E6;

        int power = 1;
        for (int i = 0; i < m; i++)
        {
            power = (power * 31) % BASE;
        }

        int targetCode = 0;
        for (int i = 0; i < m; i++)
        {
            targetCode = (targetCode * 31 + target[i]) % BASE;
        }

        int sourceCode = 0;
        for (int i = 0; i < n; i++)
        {
            sourceCode = (sourceCode * 31 + source[i]) % BASE;

            if (i < m - 1)
                continue;

            if (i >= m)
                sourceCode = (sourceCode - source[i - m] * power) % BASE;

            if (sourceCode < 0)
                sourceCode += BASE;

            if (sourceCode == targetCode)
            {
                if (source.substr(i - m + 1, m) == target)
                    return i - m + 1;
            }
        }

        return -1;
    }

public:
    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 1;

        int count = 1;
        string source = a;
        while (source.size() < b.size())
        {
            count++;
            source += a;
        }

        if (source == b)
            return count;

        if (rabinKarp(source, b) != -1)
            return count;

        if (rabinKarp(source + a, b) != -1)
            return count + 1;

        return -1;
    }
};