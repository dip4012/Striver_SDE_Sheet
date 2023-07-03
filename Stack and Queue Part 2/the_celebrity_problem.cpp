#include <bits/stdc++.h>
using namespace std;
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    int lo = 0, hi = n - 1;

    while (lo < hi)
    {
        if (knows(lo, hi))
            lo++;
        else
            hi--;
    }

    int celeb = lo;
    bool knowsAny = false, knownToAll = true;

    for (int i = 0; i < n; i++)
    {
        if (i == celeb)
            continue;

        if (knows(celeb, i))
        {
            knowsAny = true;
            break;
        }

        if (!knows(i, celeb))
        {
            knownToAll = false;
            break;
        }
    }

    if (!knowsAny && knownToAll)
        return celeb;
    else
        return -1;
}