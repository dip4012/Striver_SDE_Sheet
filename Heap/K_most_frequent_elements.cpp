#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> uniques;
    unordered_map<int, int> freq;

    int partiton(int l, int r, int pivotIndex)
    {
        int pivotFrequency = freq[uniques[pivotIndex]];
        swap(uniques[r], uniques[pivotIndex]);

        int cur = l;
        for (int i = l; i < r; i++)
        {
            if (freq[uniques[i]] > pivotFrequency)
            {
                swap(uniques[cur], uniques[i]);
                cur++;
            }
        }

        swap(uniques[cur], uniques[r]);
        return cur;
    }

    void quickSelect(int l, int r, int k)
    {
        if (l == r)
            return;

        int pivotIndex = (l + r) / 2;
        int partitionIndex = partiton(l, r, pivotIndex);

        if (partitionIndex == k - 1)
            return;
        else if (partitionIndex < k - 1)
            quickSelect(partitionIndex + 1, r, k);
        else
            quickSelect(l, partitionIndex - 1, k);
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int n : nums)
            freq[n] += 1;

        for (pair<int, int> p : freq)
            uniques.push_back(p.first);

        quickSelect(0, uniques.size() - 1, k);

        vector<int> ans(k);
        copy(uniques.begin(), uniques.begin() + k, ans.begin());
        return ans;
    }
};