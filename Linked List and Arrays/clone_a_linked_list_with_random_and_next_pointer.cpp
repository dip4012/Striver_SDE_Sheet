#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *crawl = head;
        while (crawl)
        {
            Node *newNode = new Node(crawl->val);
            newNode->next = crawl->next;
            crawl->next = newNode;
            crawl = crawl->next->next;
        }

        crawl = head;
        while (crawl)
        {
            crawl->next->random = crawl->random ? crawl->random->next : nullptr;
            crawl = crawl->next->next;
        }

        crawl = head;
        Node *res = new Node(0);
        Node *crawlRes = res;
        while (crawl)
        {
            Node *nex = crawl->next->next;
            crawlRes->next = crawl->next;
            crawlRes = crawlRes->next;
            crawl->next = nex;
            crawl = crawl->next;
        }

        return res->next;
    }
};