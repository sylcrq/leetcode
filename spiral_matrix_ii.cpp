#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) 
{
    vector<vector<int> > result(n, vector<int>(n));

    int horizontal_first = 0;   // 水平向右行
    int horizontal_last = n-1;  // 水平向左行
    int vertical_right = n-1;   // 垂直向下行
    int vertical_left = 0;      // 垂直向上行

    int num = 1;
    int count = n;

    while(1)
    {
        // 递归的思想
        if(count <= 0) break;

        if(count == 1)
        {
            for(int i=horizontal_first; i < n-horizontal_first; i++)
            {
                result[horizontal_first][i] = num++;
            }
            break;
        }

        // 1. 水平向右行
        for(int i=horizontal_first; i < n-horizontal_first; i++)
        {
            result[horizontal_first][i] = num++;
        }
        horizontal_first++;
        count--;

        //if(count <= 0) break;
        
        // 2. 垂直向下行
        for(int i=n-vertical_right; i < vertical_right+1; i++)
        {
            result[i][vertical_right] = num++;
        }
        vertical_right--;

        // 3. 水平向左行
        for(int i=horizontal_last-1; i >= (n-1)-horizontal_last; i--)
        {
            result[horizontal_last][i] = num++;
        }
        horizontal_last--;
        count--;

        //if(count <= 0) break;

        // 4. 垂直向上行
        for(int i=(n-2)-vertical_left; i >= vertical_left+1; i--)
        {
            result[i][vertical_left] = num++;
        }
        vertical_left++;
    }

    return result;
}
