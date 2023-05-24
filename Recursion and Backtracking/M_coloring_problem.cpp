#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &mat, vector<int> &color, int node, int c, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (mat[i][node] && color[i] == c)
            return false;
    }
    return true;
}

bool colorGraph(vector<vector<int>> &mat, vector<int> &color, int node, int n, int m)
{
    if (node == n)
    {
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        if (isValid(mat, color, node, c, n))
        {
            color[node] = c;
            if (colorGraph(mat, color, node + 1, n, m))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> color(n, 0);
    if (colorGraph(mat, color, 0, n, m))
        return "YES";
    else
        return "NO";
}