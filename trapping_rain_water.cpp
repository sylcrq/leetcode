#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int trap(int A[], int n) 
{
    if(n <= 0)
        return 0;

    int result = 0;
    int left_max = 0;   // 当前坐标左边出现的最高海拔
    int right_max = 0;  // 当前坐标右边出现的最高海拔

    vector<pair<int, int> > range(n, pair<int, int>(0, 0));
    
    // 从左往右扫描
    for(int i=0; i<n; i++)
    {
        range[i].first = left_max;

        left_max = std::max(left_max, A[i]);
    }

    // 从右往左扫描
    for(int i=n-1; i>=0; i--)
    {
        range[i].second = right_max;

        right_max = std::max(right_max, A[i]);
    }

    // 计算rain water
    for(int i=0; i<n; i++)
    {
        if(A[i] < range[i].first && A[i] < range[i].second)
        {
            result += std::min(range[i].first, range[i].second) - A[i];
        }
    }

    return result;
}

