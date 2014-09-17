#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
    if(grid.empty())
        return 0;

    int m = grid.size();
    int n = grid[0].size();

    // Path Num Info
    vector<vector<int> > info(m, vector<int>(n, 0));

    info[0][0] = grid[0][0];

    for(int i=1; i<n; i++)
    {
        info[0][i] = grid[0][i] + info[0][i-1];
        //cout << info[0][i] << endl;
    }

    for(int i=1; i<m; i++)
    {
        info[i][0] = grid[i][0] + info[i-1][0];
        //cout << info[i][0] << endl;
    }

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            info[i][j] = min(info[i-1][j], info[i][j-1]) + grid[i][j];
            //cout << info[i][j] << "-";
        }
        //cout << endl;
    }

    return info[m-1][n-1];
}
