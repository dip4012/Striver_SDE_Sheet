#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hashSet;
        for (int n : nums)
            hashSet.insert(n);

        int maxStreak = 0;
        for (int n : nums)
        {
            if (hashSet.find(n - 1) == hashSet.end())
            {
                int curNum = n;
                int curStreak = 1;
                while (hashSet.find(curNum + 1) != hashSet.end())
                {
                    curNum++;
                    curStreak++;
                }
                maxStreak = max(maxStreak, curStreak);
            }
        }

        return maxStreak;
    }
};