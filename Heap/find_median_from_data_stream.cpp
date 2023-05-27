#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    // taking two heaps. A max-heap to store the lesser numbers and a min-heap to store the greater numbers
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

public:
    void addNum(int num)
    {
        // add to lesser heap
        lo.push(num);

        // balance the heaps
        hi.push(lo.top());
        lo.pop();

        if (hi.size() > lo.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian()
    {
        if (lo.size() != hi.size())
            return lo.top();
        else
            return (lo.top() + hi.top()) * 0.5;
    }
};