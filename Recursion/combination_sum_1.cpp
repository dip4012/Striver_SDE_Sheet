#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void findCombinationSum(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &cur, int i, int n, int target)
    {
        if (i == n)
        {
            if (target == 0)
                ans.push_back(cur);
            return;
        }

        if (candidates[i] <= target)
        {
            cur.push_back(candidates[i]);
            findCombinationSum(candidates, ans, cur, i, n, target - candidates[i]);
            cur.pop_back();
        }
        findCombinationSum(candidates, ans, cur, i + 1, n, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> cur;
        vector<vector<int>> ans;
        findCombinationSum(candidates, ans, cur, 0, candidates.size(), target);
        return ans;
    }
};