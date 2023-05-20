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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *left = head, *right = head;
        while (n)
        {
            right = right->next;
            n--;
        }

        if (!right)
        {
            ListNode *temp = left->next;
            left->next = nullptr;
            delete (left);
            return temp;
        }

        while (right->next)
        {
            left = left->next;
            right = right->next;
        }

        ListNode *temp = left->next;
        left->next = temp->next;
        temp->next = nullptr;
        delete (temp);

        return head;
    }
};