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
    int lengthOfLinkList(ListNode *head)
    {
        ListNode *crawl = head;
        int l = 0;
        while (crawl)
        {
            l++;
            crawl = crawl->next;
        }
        return l;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = lengthOfLinkList(head);

        ListNode *newHead = new ListNode();
        newHead->next = head;
        ListNode *prev = newHead, *cur, *nex;

        while (len >= k)
        {
            cur = prev->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            len -= k;
        }

        return newHead->next;
    }
};