#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
{
    if(obstacleGrid.empty() || obstacleGrid[0].empty()) 
        return 0;

    if(obstacleGrid[0][0] == 1) 
        return 0;

    int row = obstacleGrid.size();
    int column = obstacleGrid[0].size();

    // 优化空间复杂度O(N) & 代码逻辑
    vector<int> path(column, 0);
    path[0] = 1;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(obstacleGrid[i][j] == 1)
                path[j] = 0;
            else if(j > 0)
                path[j] += path[j-1];
        }
    }

    return path[column-1];
#if 0
    vector<vector<int> > path(row, vector<int>(column, 0));

    path[0][0] = 1;

    // first row
    for(int i=1; i<column; i++)
    {
        if(obstacleGrid[0][i] == 1)
            continue;
        
        path[0][i] = path[0][i-1];
    }

    // first column
    for(int i=1; i<row; i++)
    {
        if(obstacleGrid[i][0] == 1)
            continue;

        path[i][0] = path[i-1][0];
    }

    for(int i=1; i<row; i++)
    {
        for(int j=1; j<column; j++)
        {
            if(obstacleGrid[i][j] == 1)
                continue;

            path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }

    return path[row-1][column-1];
#endif
}

