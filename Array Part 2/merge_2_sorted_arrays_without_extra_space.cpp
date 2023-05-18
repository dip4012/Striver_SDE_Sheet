#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int i, int j)
    {
        if (arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = m + n;
        int gap = len / 2 + len % 2;
        while (gap > 0)
        {
            int left = 0;
            int right = left + gap;
            while (right < len)
            {
                if (left < m && right >= m)
                    swapIfGreater(nums1, nums2, left, right - m);
                if (left < m && right < m)
                    swapIfGreater(nums1, nums1, left, right);
                if (left >= m && right >= m)
                    swapIfGreater(nums2, nums2, left - m, right - m);

                left++;
                right++;
            }
            if (gap == 1)
                break;

            gap = gap / 2 + gap % 2;
        }

        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
    }
};