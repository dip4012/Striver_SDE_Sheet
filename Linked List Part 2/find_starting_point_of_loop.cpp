#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;
        fast = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};