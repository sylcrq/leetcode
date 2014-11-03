#include <algorithm>
#include <vector>

using namespace std;

// Dynamic Programming (从上往下扫描)
// PS: 从下往上扫描更简便
int minimumTotal(vector<vector<int> > &triangle) 
{
    if(triangle.empty())
        return 0;

    int n = triangle.size();

    // 每一层path sum的计算结果
    vector<int> result(n, 0);

    for(int i=0; i<n; i++)
    {
        int prev = result[0];  // Note !

        for(int j=0; j<i+1; j++)
        {
            if(j == 0)
            {
                result[0] += triangle[i][0];
            }
            else if(j == i)
            {
                result[i] = prev + triangle[i][i];
            }
            else
            {
                int tmp = std::min(prev + triangle[i][j], result[j] + triangle[i][j]);

                prev = result[j];
                result[j] = tmp;
            }
        }
    }

    int min = *std::min_element(result.begin(), result.end());

    return min;
}

