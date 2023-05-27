#include <bits/stdc++.h>
using namespace std;

// Priority Queue approach
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        return pq.top();
    }
};

// Quick Select approach
class Solution
{
    int partiton(vector<int> &nums, int l, int r, int pivotIndex)
    {
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[r]);
        int cur = l;
        for (int i = l; i < r; i++)
        {
            if (nums[i] > pivotValue)
            {
                swap(nums[cur], nums[i]);
                cur++;
            }
        }
        swap(nums[cur], nums[r]);
        return cur;
    }

    int quickSelect(vector<int> &nums, int l, int r, int k)
    {
        if (l == r)
        {
            return nums[l];
        }

        int pivotIndex = (l + r) / 2;
        int partitionIndex = partiton(nums, l, r, pivotIndex);

        if (partitionIndex == k - 1)
            return nums[partitionIndex];
        else if (partitionIndex < k - 1)
            return quickSelect(nums, partitionIndex + 1, r, k);
        else
            return quickSelect(nums, l, partitionIndex - 1, k);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};