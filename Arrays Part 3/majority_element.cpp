#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ele;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                ele = nums[i];
            }

            if (nums[i] == ele)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return ele;
    }
};