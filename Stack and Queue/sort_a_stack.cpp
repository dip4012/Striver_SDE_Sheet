#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int element)
{
    // Base case: If stack is empty or current element is greater than top element of stack
    if (stack.empty() || element > stack.top())
    {
        stack.push(element);
        return;
    }

    // pop the top element of stack
    int top = stack.top();
    stack.pop();

    // check for the rest stack for the correct position of element
    sortedInsert(stack, element);

    // insert back the popped element
    stack.push(top);
}

void sortStack(stack<int> &stack)
{
    // Base case: if stack is empty
    if (stack.empty())
    {
        return;
    }

    // remove top element
    int top = stack.top();
    stack.pop();

    // sort the remaining stack
    sortStack(stack);

    // insert the popped element into the sorted stack
    sortedInsert(stack, top);
}