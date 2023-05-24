#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool sudokuSolver(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, row, col, ch))
                        {
                            board[row][col] = ch;
                            if (sudokuSolver(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[row][k] == ch || board[k][col] == ch || board[3 * (row / 3) + k / 3][3 * (col / 3) + k % 3] == ch)
                return false;
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        sudokuSolver(board);
    }
};