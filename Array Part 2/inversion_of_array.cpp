#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int left, int mid, int right)
{
    int invCount = 0;
    int temp[right - left + 1];
    int i = left, j = mid, k = 0;

    while (i < mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            invCount += mid - i;
            temp[k++] = arr[j++];
        }
    }

    while (i < mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i - left];

    return invCount;
}

long long mergeSort(long long *arr, int left, int right)
{
    long long invCount = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        invCount += mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid + 1, right);
    }
    return invCount;
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}