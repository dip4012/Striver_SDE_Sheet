#include <bits/stdc++.h>
using namespace std;

void findSubsetSum(vector<int> &nums, vector<int> &ans, int sum, int i, int n)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }

    findSubsetSum(nums, ans, sum, i + 1, n);
    findSubsetSum(nums, ans, sum + nums[i], i + 1, n);
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    findSubsetSum(nums, ans, 0, 0, nums.size());
    sort(ans.begin(), ans.end());
    return ans;
}