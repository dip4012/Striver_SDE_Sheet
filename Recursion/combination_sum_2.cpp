#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void findCombinationSum2(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &cur, int target, int index, int n)
    {
        if (target == 0)
        {
            ans.push_back(cur);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (candidates[i] > target)
                break;
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            cur.push_back(candidates[i]);
            findCombinationSum2(candidates, ans, cur, target - candidates[i], i + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        findCombinationSum2(candidates, ans, cur, target, 0, candidates.size());
        return ans;
    }
};