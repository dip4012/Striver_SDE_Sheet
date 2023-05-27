#include <bits/stdc++.h>
using namespace std;

int lchild(int i)
{
    return 2 * i + 1;
}

int rchild(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void heapify(vector<int> &heap, int size, int node)
{
    int l = lchild(node), r = rchild(node), smallest = node;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != node)
    {
        swap(heap[node], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void insertElement(vector<int> &heap, int &size, int val)
{
    heap.push_back(val);
    size++;

    int i = size - 1;
    while (i > 0 && heap[parent(i)] > heap[i])
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int extractMin(vector<int> &heap, int &size)
{
    int root = heap[0];
    swap(heap[0], heap[size - 1]);
    heap.pop_back();
    size--;

    heapify(heap, size, 0);

    return root;
}

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    int size = 0;
    vector<int> heap;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
        {
            insertElement(heap, size, q[i][1]);
        }
        else
        {
            ans.push_back(extractMin(heap, size));
        }
    }

    return ans;
}