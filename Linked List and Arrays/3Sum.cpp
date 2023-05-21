#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            while (i < n - 2 && !res.empty() && nums[i] == res.back()[0])
                i++;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == res.back()[1])
                        left++;
                    while (left < right && nums[right] == res.back()[2])
                        right--;
                }
                else if (sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};