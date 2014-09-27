#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) 
{
    vector<int> result;

    if(matrix.empty()) return result;

    int row = matrix.size();
    int column = matrix[0].size();

    int horizontal_first = 0;
    int horizontal_last = row - 1;
    int vertical_left = 0;
    int vertical_right = column - 1;

    int count_row = row;
    int count_column = column;

    while(1)
    {
        // 1. 水平向右行
        for(int i=horizontal_first; i < column-horizontal_first; i++)
        {
            result.push_back(matrix[horizontal_first][i]);
        }
        horizontal_first++;

        count_row--;
        if(count_row <= 0) break;

        // 2. 垂直向下列
        for(int i=column-vertical_right; i < row-column+1+vertical_right; i++)
        {
            result.push_back(matrix[i][vertical_right]);
        }
        vertical_right--;

        count_column--;
        if(count_column <= 0) break;

        // 3. 水平向左行
        for(int i=column-row-1+horizontal_last; i >= row-horizontal_last-1; i--)
        {
            result.push_back(matrix[horizontal_last][i]);
        }
        horizontal_last--;

        count_row--;
        if(count_row <= 0) break;

        // 4. 垂直向上行
        for(int i=row-2-vertical_left; i >= vertical_left+1; i--)
        {
            result.push_back(matrix[i][vertical_left]);
        }
        vertical_left++;

        count_column--;
        if(count_column <= 0) break;
    }

    return result;
}

