#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<pair<int, int>> stk;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push({val, min(val, stk.empty() ? INT_MAX : stk.top().second)});
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};