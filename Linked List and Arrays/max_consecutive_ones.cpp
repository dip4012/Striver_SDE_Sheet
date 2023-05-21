#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxOnes = 0, curOnes = 0;
        for (int n : nums)
        {
            if (n == 1)
                curOnes++;
            else
            {
                maxOnes = max(maxOnes, curOnes);
                curOnes = 0;
            }
        }
        maxOnes = max(maxOnes, curOnes);
        return maxOnes;
    }
};