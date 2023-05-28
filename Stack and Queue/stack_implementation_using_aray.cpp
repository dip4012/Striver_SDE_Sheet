#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack
{
    int *stack;
    int maxSize;
    int curSize;

public:
    Stack(int capacity)
    {
        stack = new int[capacity];
        curSize = 0;
        maxSize = capacity;
    }

    void push(int num)
    {
        if (curSize < maxSize)
            stack[curSize++] = num;
    }

    int pop()
    {
        if (curSize == 0)
            return -1;
        return stack[--curSize];
    }

    int top()
    {
        if (curSize == 0)
            return -1;
        return stack[curSize - 1];
    }

    int isEmpty()
    {
        if (curSize == 0)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if (curSize == maxSize)
            return 1;
        else
            return 0;
    }
};