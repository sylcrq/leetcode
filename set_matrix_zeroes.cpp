#include <vector>

using namespace std;

// 空间复杂度O(n) 
void setZeroes(vector<vector<int> > &matrix)
{
    if(matrix.empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> column_flag(n, 0);  // 记录需要清零的列

    int count = m;

    while(count > 0)
    {
        bool clear_row = false;

        for(int i=0; i<n; i++)
        {
            if(matrix[count-1][i] == 0)
            {
                column_flag[i] = 1;
                clear_row = true;
            }
        }

        // 行清零
        if(clear_row)
        {
            for(int i=0; i<n; i++)
            {
                matrix[count-1][i] = 0;
            }
        }

        count--;
    }

    for(int i=0; i<n; i++)
    {
        if(column_flag[i] == 1)
        {
            // 列清零
            for(int j=0; j<m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
}

// 空间复杂度O(1) 
void setZeroes_ii(vector<vector<int> > &matrix)
{
    if(matrix.empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();

    bool clear_first_row = false;
    bool clear_first_column = false;

    for(int i=0; i<n; i++)
    {
        if(matrix[0][i] == 0)
        {
            clear_first_row = true;
        }
    }

    for(int i=0; i<m; i++)
    {
        if(matrix[i][0] == 0)
        {
            clear_first_column = true;
        }
    }

    // 第一行(列)记录需要清零的列(行)
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if(clear_first_row)
    {
        for(int i=0; i<n; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if(clear_first_column)
    {
        for(int i=0; i<m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

