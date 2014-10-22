#include <vector>
#include "string.h"

using namespace std;

bool is_valid(char c, char flag[9]);

bool isValidSudoku(vector<vector<char> > &board)
{
    if(board.empty() || board[0].empty())
        return false;

    int row = board.size();
    int column = board[0].size();

    if(row != 9 || column != 9)
        return false;

    char row_flag[9] = {0};
    char column_flag[9] = {0};

    for(int i=0; i<9; i++)
    {
        memset(row_flag, 0, sizeof(row_flag));
        memset(column_flag, 0, sizeof(column_flag));

        for(int j=0; j<9; j++)
        {
            // check by row
            if(!is_valid(board[i][j], row_flag))
                return false;

            // check by column
            if(!is_valid(board[j][i], column_flag))
                return false;
        }
    }

    for(int i=0; i<9; i+=3)
    {
        for(int j=0; j<9; j+=3)
        {
            memset(row_flag, 0, sizeof(row_flag));

            for(int m=i; m<i+3; m++)
            {
                for(int n=j; n<j+3; n++)
                {
                    if(!is_valid(board[m][n], row_flag))
                        return false;
                }
            }

        }
    }

    return true;
}

bool is_valid(char c, char flag[9])
{
    if(c >= '1' && c <= '9')
    {
        int val = c - '1';

        if(flag[val] == 1) return false;

        flag[val] = 1;
    }
    else if(c != '.')
    {
        return false;
    }

    return true;
}

