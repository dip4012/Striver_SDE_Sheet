#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *mergeTwoLinkedList(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *merged;
    if (a->data <= b->data)
    {
        merged = a;
        merged->child = mergeTwoLinkedList(a->child, b);
    }
    else
    {
        merged = b;
        merged->child = mergeTwoLinkedList(a, b->child);
    }

    merged->next = nullptr;
    return merged;
}

Node *flattenLinkedList(Node *head)
{
    if (!head || !head->next)
        return head;
    head->next = flattenLinkedList(head->next);
    head = mergeTwoLinkedList(head, head->next);
    return head;
}
