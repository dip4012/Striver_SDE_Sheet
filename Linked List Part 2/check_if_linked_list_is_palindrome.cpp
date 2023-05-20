#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *cur = head, *prev = nullptr;
        while (cur)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseLinkedList(slow->next);
        slow = slow->next;
        fast = head;
        while (slow)
        {
            if (fast->val != slow->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};