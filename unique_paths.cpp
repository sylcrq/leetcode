#include <vector>

using namespace std;

// 动态规划
// Paths[i][j] = Paths[i-1][j] + Paths[i][j-1]
int uniquePaths(int m, int n)
{
    vector<vector<int> > paths(m, vector<int>(n, 1));

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            paths[i][j] = paths[i-1][j] + paths[i][j-1];
        }
    }

    return paths[m-1][n-1];
}
