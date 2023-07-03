#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void clean_deque(vector<int> &nums, deque<int> &deq, int i, int k)
    {
        if (!deq.empty() && deq.front() == i - k)
            deq.pop_front();

        while (!deq.empty() && nums[i] > nums[deq.back()])
            deq.pop_back();
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (!n || !k)
            return vector<int>();
        if (k == 1)
            return nums;

        deque<int> deq;
        vector<int> ans(n - k + 1);
        for (int i = 0; i < k; i++)
        {
            clean_deque(nums, deq, i, k);
            deq.push_back(i);
        }
        ans[0] = nums[deq.front()];
        for (int i = k; i < n; i++)
        {
            clean_deque(nums, deq, i, k);
            deq.push_back(i);
            ans[i - k + 1] = nums[deq.front()];
        }

        return ans;
    }
};