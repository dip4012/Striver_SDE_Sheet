#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void findSubsets(vector<int> &nums, vector<vector<int>> &ans, vector<int> &cur, int i, int n)
    {
        if (i == n)
        {
            if (find(ans.begin(), ans.end(), cur) == ans.end())
                ans.push_back(cur);
            return;
        }

        findSubsets(nums, ans, cur, i + 1, n);
        cur.push_back(nums[i]);
        findSubsets(nums, ans, cur, i + 1, n);
        cur.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        findSubsets(nums, ans, cur, 0, nums.size());
        return ans;
    }
};