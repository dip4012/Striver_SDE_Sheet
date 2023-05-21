#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
    int pos;
    int start;
    int end;
};

bool comparator(Meeting a, Meeting b)
{
    if (a.end < b.end)
        return true;
    else if (a.end > b.end)
        return false;
    else if (a.pos < b.pos)
        return true;
    else
        return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    Meeting m[n];
    for (int i = 0; i < n; i++)
    {
        m[i].pos = i + 1;
        m[i].start = start[i];
        m[i].end = end[i];
    }

    sort(m, m + n, comparator);
    vector<int> ans;
    ans.push_back(m[0].pos);
    int limit = m[0].end;
    for (int i = 1; i < n; i++)
    {
        if (m[i].start > limit)
        {
            ans.push_back(m[i].pos);
            limit = m[i].end;
        }
    }

    return ans;
}