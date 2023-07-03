#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int freshOranges = 0, row = grid.size(), col = grid[0].size();

        // prepare the queue for commencing bfs by pushing the coordinates of rotten oranges and also count the freshOranges initially
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    freshOranges++;
            }
        }
        // mark the level end with {-1, -1}
        q.push({-1, -1});

        int minutesElapsed = -1;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // traverse the queue while it is no-empty
        while (!q.empty())
        {
            // extract the top element
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;

            // if (i, j) is equal to (-1, -1) then the level is completed and 1 min has been elapsed
            if (i == -1)
            {
                minutesElapsed++;
                if (!q.empty())
                    q.push({-1, -1});
            }
            else
            {
                // visit all the adjacent oranges of (i, j) and check for a fresh orange and rot it
                for (pair<int, int> d : directions)
                {
                    int adj_i = i + d.first, adj_j = j + d.second;

                    if (adj_i >= 0 && adj_i < row && adj_j >= 0 && adj_j < col)
                    {
                        if (grid[adj_i][adj_j] == 1)
                        {
                            grid[adj_i][adj_j] = 2;
                            freshOranges--;
                            q.push({adj_i, adj_j});
                        }
                    }
                }
            }
        }

        return freshOranges ? -1 : minutesElapsed;
    }
};