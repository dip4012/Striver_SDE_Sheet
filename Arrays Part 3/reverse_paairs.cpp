#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int merge(vector<int> &nums, int left, int mid, int right)
    {
        int i = left, j = mid + 1;
        int revCount = 0;
        for (i = left; i <= mid; i++)
        {
            while (j <= right && nums[i] > 2ll * nums[j])
                j++;
            revCount += j - mid - 1;
        }

        vector<int> temp;
        i = left;
        j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= right)
            temp.push_back(nums[j++]);
        for (i = left; i <= right; i++)
            nums[i] = temp[i - left];

        return revCount;
    }

    int mergeSort(vector<int> &nums, int left, int right)
    {
        int revCount = 0;
        if (left < right)
        {
            int mid = (left + right) / 2;
            revCount += mergeSort(nums, left, mid);
            revCount += mergeSort(nums, mid + 1, right);
            revCount += merge(nums, left, mid, right);
        }
        return revCount;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};