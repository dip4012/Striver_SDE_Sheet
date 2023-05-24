#include <bits/stdc++.h>
using namespace std;

void insertSolution(vector<vector<int>> &ans, vector<vector<int>> &solution, int n)
{
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t.push_back(solution[i][j]);
        }
    }
    ans.push_back(t);
}

void ratMoveInMaze(vector<vector<int>> &maze, vector<vector<int>> &ans, vector<vector<int>> &solution, int row, int col, int n)
{
    if (row == n - 1 && col == n - 1)
    {
        solution[row][col] = 1;
        insertSolution(ans, solution, n);
        return;
    }

    if (row < 0 || row == n || col < 0 || col == n || maze[row][col] == 0 || solution[row][col] == 1)
        return;

    solution[row][col] = 1;

    ratMoveInMaze(maze, ans, solution, row, col + 1, n);
    ratMoveInMaze(maze, ans, solution, row, col - 1, n);
    ratMoveInMaze(maze, ans, solution, row - 1, col, n);
    ratMoveInMaze(maze, ans, solution, row + 1, col, n);

    solution[row][col] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> solution(n, vector<int>(n, 0));
    ratMoveInMaze(maze, ans, solution, 0, 0, n);
    return ans;
}