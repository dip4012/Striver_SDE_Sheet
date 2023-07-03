#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> a, int n)
{
    stack<int> st;
    vector<int> next(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[i] <= a[st.top()])
            st.pop();

        if (st.empty())
            next[i] = n;
        else
            next[i] = st.top();

        st.push(i);
    }
    return next;
}

vector<int> prevSmaller(vector<int> a, int n)
{
    stack<int> st;
    vector<int> prev(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] <= a[st.top()])
            st.pop();

        if (st.empty())
            prev[i] = -1;
        else
            prev[i] = st.top();

        st.push(i);
    }
    return prev;
}

vector<int> maxMinWindow(vector<int> a, int n)
{
    vector<int> ans(n, INT_MIN);
    vector<int> next(n), prev(n);

    next = nextSmaller(a, n);
    prev = prevSmaller(a, n);

    for (int i = 0; i < n; i++)
    {
        int len = next[i] - prev[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}