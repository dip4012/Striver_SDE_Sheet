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
    int lengthOfLinkedList(ListNode *head)
    {
        int len = 0;
        ListNode *crawl = head;
        while (crawl)
        {
            len++;
            crawl = crawl->next;
        }
        return len;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int l = lengthOfLinkedList(head);
        if (l == 0)
            return head;
        k = k % l;
        ListNode *left = head, *right = head;
        while (k--)
            right = right->next;
        while (right->next)
        {
            left = left->next;
            right = right->next;
        }
        right->next = head;
        head = left->next;
        left->next = nullptr;
        return head;
    }
};