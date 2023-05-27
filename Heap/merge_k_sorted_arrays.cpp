#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> ans;

    // create a min-heap to store the store atmost K nodes at a time;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < k; i++)
        pq.push({kArrays[i][0], {i, 0}});

    // keep adding elements from heap into the array until heap is empty
    while (!pq.empty())
    {
        // get the top element from the heap
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();

        ans.push_back(top.first);
        int i = top.second.first, j = top.second.second;

        if (j + 1 < kArrays[i].size())
            pq.push({kArrays[i][j + 1], {i, j + 1}});
    }

    return ans;
}