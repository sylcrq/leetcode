#include <vector>

using namespace std;

void rotate(vector< vector<int> >& matrix)
{
    int n = matrix.size();

    vector< vector<int> > result(n, vector<int>(n));

    // 顺时针旋转90°
    // B[i][j] = A[n-j-1][i]
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            result[i][j] = matrix[n-j-1][i];
        }
    }

    // swap
    for(int i=0; i<n; i++)
    {
        matrix[i].swap(result[i]);
    }
}
