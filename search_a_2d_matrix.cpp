#include <algorithm>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target)
{
    if(matrix.empty())
        return false;

    int m = matrix.size();
    int n = matrix[0].size();

    int start = 0;
    int end = m-1;

    // 二分
    while(start <= end)
    {
        int mid = (start + end) / 2;

        if(target < matrix[mid][0])
        {
            end = mid - 1;
        }
        else if(target > matrix[mid][n-1])
        {
            start = mid + 1;
        }
        else
        {
            return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
        }
    }

    return false;
}
