//#include <bitset>
//#include <iostream>
#include <vector>

using namespace std;

bool solveSudoku_helper(vector<vector<char> >& board,
                        vector<vector<char> >& row,
                        vector<vector<char> >& column,
                        vector<vector<char> >& grid,
                        int i, int j);

void solveSudoku(vector<vector<char> > &board) 
{
    // use std::bitset ?
    vector<vector<char> > row(9, vector<char>(9, 0));
    vector<vector<char> > column(9, vector<char>(9, 0));
    vector<vector<char> > grid(9, vector<char>(9, 0));

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j] == '.')
                continue;

            int index = board[i][j] - '1';

            row[i][index] = 1;
            column[j][index] = 1;
            grid[(i/3)*3+j/3][index] = 1;
        }
    }

    solveSudoku_helper(board, row, column, grid, 0, 0);
}

// 递归
bool solveSudoku_helper(vector<vector<char> >& board,
                        vector<vector<char> >& row,
                        vector<vector<char> >& column,
                        vector<vector<char> >& grid,
                        int i, int j)
{
    if(j > 8)
    {
        i++;
        j = 0;
    }

    if(i > 8)
        return true;

    if(board[i][j] != '.')
        return solveSudoku_helper(board, row, column, grid, i, j+1);

    for(int k=0; k<9; k++)
    {
        if(!row[i][k] && !column[j][k] && !grid[(i/3)*3+j/3][k])
        {
            board[i][j] = '1' + k;

            row[i][k] = 1;
            column[j][k] = 1;
            grid[(i/3)*3+j/3][k] = 1;

            if(solveSudoku_helper(board, row, column, grid, i, j+1))
                return true;

            // clear
            row[i][k] = 0;
            column[j][k] = 0;
            grid[(i/3)*3+j/3][k] = 0;

            board[i][j] = '.';
        }
    }

    return false;
}

