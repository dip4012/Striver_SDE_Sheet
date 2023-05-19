#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long copy_n = n;
        if (n < 0)
            copy_n = -copy_n;

        while (copy_n)
        {
            if (copy_n % 2)
            {
                ans = ans * x;
                copy_n--;
            }
            else
            {
                x = x * x;
                copy_n = copy_n / 2;
            }
        }

        if (n < 0)
            ans = 1.0 / ans;

        return ans;
    }
};