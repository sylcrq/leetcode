#include <iostream>
#include <vector>

using namespace std;

int result = 0;

void resolve(vector<vector<int> >& solution, int row, int n);
bool is_valid(vector<vector<int> >& solution, int row, int column, int n);
void print_solution(vector<vector<int> >& solution, int i, int n);

int totalNQueens(int n)
{
    vector<vector<int> > solution(n, vector<int>(n, 0));

    resolve(solution, 0, n);

    return result;
}

// 递归
void resolve(vector<vector<int> >& solution, int row, int n)
{
    if(row == n)
    {
        result++;
        //print_solution(solution, result, n);
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(is_valid(solution, row, i, n))
        {
            solution[row][i] = 1;

            resolve(solution, row + 1, n);

            // Clear
            solution[row][i] = 0;
        }
    }

}

bool is_valid(vector<vector<int> >& solution, int row, int column, int n)
{
    // 同一列上方
    for(int i=0; i<row; i++)
    {
        if(solution[i][column] == 1)
            return false;
    }

    // 左上方对角线
    int j = column - 1;
    for(int i=row-1; i>=0 && j>=0; i--, j--)
    {
        if(solution[i][j] == 1)
            return false;
    }

    // 右上方对角线
    j = column + 1;
    for(int i=row-1; i>=0 && j<n; i--, j++)
    {
        if(solution[i][j] == 1)
            return false;
    }

    return true;
}


void print_solution(vector<vector<int> >& solution, int i, int n)
{
    cout << "solution: " << i << endl;

    int row = 0;
    
    while(row < n)
    {
        for(int i=0; i<n; i++)
        {
            cout << solution[row][i] << " ";
        }

        cout << endl;

        row++;
    }
}

