#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>

using namespace std;

bool is_valid(vector<int>& solution, int row, int column);

vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string> > result;

    // 第i行的Queen放在第solution[i]列
    vector<int> solution(n, -1);

    int row = 0;

    // 非递归
    while(1)
    {
        int column;

        for(column = solution[row]+1; column < n; column++)
        {
            if(is_valid(solution, row, column))
            {
                solution[row] = column;

                if(row == n-1)
                {
                    // solution
                    vector<string> tmp(n, string(n, '.'));

                    for(int i=0; i<n; i++)
                    {
                        tmp[i][solution[i]] = 'Q';
                    }

                    result.push_back(tmp);

                    solution[row] = -1;  // clear
                    row--;  // 回溯
                }
                else
                {
                    row++;
                }

                break;
            }
        }

        if(column == n)
        {
            solution[row] = -1;  // clear
            row--;  // 回溯
        }

        if(row < 0)
        {
            break;  // complete
        }
    }

    return result;
}

bool is_valid(vector<int>& solution, int row, int column)
{
    for(int i=0; i<row; i++)
    {
        if(solution[i] == column || abs(solution[i]-column) == abs(i-row) )
            return false;
    }

    return true;
}

