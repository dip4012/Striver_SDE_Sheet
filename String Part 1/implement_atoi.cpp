#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int len = s.size();
        long int ans = 0;
        int i = 0;

        // skip leading spaces
        while (s[i] == ' ')
            i++;

        // find the sign
        bool negative = s[i] == '-';

        s[i] == '-' || s[i] == '+' ? i++ : i;

        // change to digits and form the number if feasible
        while (i < len && s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';

            // checking for overflow
            if (negative)
            {
                if (-ans < INT_MIN / 10 || -ans == INT_MIN / 10 && digit > 8)
                    return INT_MIN;
            }
            else
            {
                if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && digit > 7)
                    return INT_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        ans = negative ? -ans : ans;
        return ans;
    }
};