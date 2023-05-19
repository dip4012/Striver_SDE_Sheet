#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1, ele2, count1 = 0, count2 = 0;
        int n = nums.size();
        ele1 = ele2 = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (count1 == 0 && nums[i] != ele2)
            {
                ele1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0 && nums[i] != ele1)
            {
                ele2 = nums[i];
                count2 = 1;
            }
            else if (nums[i] == ele1)
            {
                count1++;
            }
            else if (nums[i] == ele2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                count1++;
            if (nums[i] == ele2)
                count2++;
        }

        vector<int> ans;
        int majPoint = n / 3;
        if (count1 > majPoint)
            ans.push_back(ele1);
        if (count2 > majPoint)
            ans.push_back(ele2);

        return ans;
    }
};