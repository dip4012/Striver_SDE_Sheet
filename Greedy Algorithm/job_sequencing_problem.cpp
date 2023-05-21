#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), [](vector<int> job1, vector<int> job2) -> bool
         { return job1[1] > job2[1]; });

    int n = jobs.size();
    int maxDeadLine = 0;
    for (int i = 0; i < n; i++)
        maxDeadLine = max(maxDeadLine, jobs[i][0]);

    set<int, greater<int>> slots;
    for (int i = maxDeadLine; i > 0; i--)
        slots.insert(i);

    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (slots.empty() || jobs[i][0] < *slots.rbegin())
            continue;

        int availableSlot = *slots.lower_bound(jobs[i][0]);
        profit += jobs[i][1];
        slots.erase(availableSlot);
    }

    return profit;
}