#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 1;

        int i = 1, k = 1;
        while (i < n)
        {
            if (nums[i] != nums[k - 1])
            {
                nums[k] = nums[i];
                k++;
            }
            i++;
        }

        return k;
    }
};