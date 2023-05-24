#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> numbers;
        int f = 1;
        for (int i = 1; i < n; i++)
        {
            numbers.push_back(i);
            f *= i;
        }
        numbers.push_back(n);
        k--;

        string ans;
        while (true)
        {
            ans += to_string(numbers[k / f]);
            numbers.erase(numbers.begin() + k / f);
            n--;
            if (n == 0)
                break;
            k = k % f;
            f = f / n;
        }

        return ans;
    }
};