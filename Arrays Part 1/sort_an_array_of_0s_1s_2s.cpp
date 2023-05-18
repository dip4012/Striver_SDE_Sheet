#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zeroes = 0, ones = 0, twos = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeroes++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }

        int i = 0;
        while (zeroes--)
            nums[i++] = 0;
        while (ones--)
            nums[i++] = 1;
        while (twos--)
            nums[i++] = 2;
    }
};