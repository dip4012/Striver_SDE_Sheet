#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int pos;
    int start;
    int end;
};

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    activity activities[n];
    for (int i = 0; i < n; i++)
    {
        activities[i].pos = i + 1;
        activities[i].start = start[i];
        activities[i].end = finish[i];
    }

    sort(activities, activities + n, [](activity a, activity b) -> bool
         { return a.end <= b.end; });

    int maxNumOfActivities = 1;
    int limit = activities[0].end;
    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= limit)
        {
            maxNumOfActivities++;
            limit = activities[i].end;
        }
    }

    return maxNumOfActivities;
}