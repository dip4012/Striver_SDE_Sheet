#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if (!st.empty() && st.top() == pairs[ch])
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};