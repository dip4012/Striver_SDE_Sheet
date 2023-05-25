#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;

        if (mid % 2)
        {
            if (arr[mid] == arr[mid - 1])
                lo = mid + 1;
            else
                hi = mid;
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
                lo = mid + 1;
            else
                hi = mid;
        }
    }
    return arr[lo];
}