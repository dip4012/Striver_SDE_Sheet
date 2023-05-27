#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    // sort both array
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Using max heap
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});

    // Using a set store visited pairs
    set<pair<int, int>> mySet;
    mySet.insert({n - 1, n - 1});

    // Output array to store the K max sum combinations
    vector<int> ans;

    while (k > 0)
    {
        // extract the top element from queue
        pair<int, pair<int, int>> top = pq.top();

        // pop the top element from queue
        pq.pop();

        int sum = top.first, x = top.second.first, y = top.second.second;

        // push the sum into the result array
        ans.push_back(sum);

        // Check if indices (x-1,y) are present in mySet
        if (mySet.find({x - 1, y}) == mySet.end())
        {
            pq.push({a[x - 1] + b[y], {x - 1, y}});
            mySet.insert({x - 1, y});
        }
        // Check if indices (x,y-1) are present in mySet
        if (mySet.find({x, y - 1}) == mySet.end())
        {
            pq.push({a[x] + b[y - 1], {x, y - 1}});
            mySet.insert({x, y - 1});
        }

        k--;
    }

    // return the result array
    return ans;
}