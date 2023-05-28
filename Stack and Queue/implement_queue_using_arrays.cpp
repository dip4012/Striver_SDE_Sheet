#include <bits/stdc++.h>
using namespace std;

class Queue
{
    vector<int> queue;
    int size;
    int start, end;

public:
    Queue()
    {
        queue = vector<int>{};
        size = 0;
        start = end = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (size == 0)
            return 1;
        else
            return 0;
    }

    void enqueue(int data)
    {
        queue.push_back(data);
        end++;
        if (start == -1)
            start = end;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
            return -1;

        size--;
        return queue[start++];
    }

    int front()
    {
        if (size == 0)
            return -1;

        return queue[start];
    }
};