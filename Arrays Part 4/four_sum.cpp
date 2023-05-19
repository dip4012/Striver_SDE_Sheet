#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> quadraplets;
        int n = nums.size();
        if (n < 4)
            return quadraplets;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                long long t = target * 1ll - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = nums[left] + nums[right];
                    if (sum == t)
                    {
                        quadraplets.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == quadraplets.back()[2])
                            left++;
                        while (left < right && nums[right] == quadraplets.back()[3])
                            right--;
                    }
                    else if (sum < t)
                        left++;
                    else
                        right--;
                }
                while (j + 1 < n - 2 && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < n - 3 && nums[i] == nums[i + 1])
                i++;
        }

        return quadraplets;
    }
};