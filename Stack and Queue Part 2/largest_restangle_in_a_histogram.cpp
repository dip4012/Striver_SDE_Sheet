#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        st.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        while (st.top() != -1)
        {
            int height = heights[st.top()];
            st.pop();
            int width = heights.size() - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};