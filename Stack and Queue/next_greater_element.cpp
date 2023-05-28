#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for (int i = 2 * nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i % nums.size()])
                st.pop();
            if (!st.empty())
                res[i % nums.size()] = nums[st.top()];
            st.push(i % nums.size());
        }
        return res;
    }
};