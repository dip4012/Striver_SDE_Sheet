#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void NQueens(vector<vector<string>> &ans, vector<bool> &ldiag, vector<bool> &rdiag, vector<bool> &row, vector<string> &board, int c, int n)
    {
        if (c == n)
        {
            ans.push_back(board);
            return;
        }

        for (int r = 0; r < n; r++)
        {
            if (row[r] && ldiag[r + n - 1 - c] && rdiag[r + c])
            {
                board[r][c] = 'Q';
                row[r] = false;
                ldiag[r + n - 1 - c] = false;
                rdiag[r + c] = false;
                NQueens(ans, ldiag, rdiag, row, board, c + 1, n);
                board[r][c] = '.';
                row[r] = true;
                ldiag[r + n - 1 - c] = true;
                rdiag[r + c] = true;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<bool> ldiag(2 * n - 1, true);
        vector<bool> rdiag(2 * n - 1, true);
        vector<bool> row(n, true);
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        NQueens(ans, ldiag, rdiag, row, board, 0, n);
        return ans;
    }
};