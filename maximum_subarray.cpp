#include <algorithm>
#include <limits>

// 动态规划 - O(N)
int maxSubArray(int A[], int n)
{
    int sum = 0;
    int max = std::numeric_limits<int>::min();

    for(int i=0; i<n; i++)
    {
        sum += A[i];

        if(sum > max)
            max = sum;
        
        if(sum < 0)
            sum = 0;
    }

    return max;
}

int maxSubArray_dac(int A[], int start, int end);

// 分治 - Divide and Conquer 
int maxSubArray_ii(int A[], int n)
{
    if(n <= 0)
        return std::numeric_limits<int>::min();

    return maxSubArray_dac(A, 0, n-1);
}


int maxSubArray_dac(int A[], int start, int end)
{
    if(start > end)
        return std::numeric_limits<int>::min();

    int mid = (start + end) / 2;

    int lmax = maxSubArray_dac(A, start, mid-1);  // 左区间的最大值
    int rmax = maxSubArray_dac(A, mid+1, end);    // 右区间的最大值

    int max = std::max(lmax, rmax);

    int sum = 0;
    int mlmax = 0;
    int mrmax = 0;

    for(int i=mid-1; i>=0; i--)
    {
        sum += A[i];

        if(sum > mlmax)
            mlmax = sum;
    }

    sum = 0;
    for(int i=mid+1; i<=end; i++)
    {
        sum += A[i];

        if(sum > mrmax)
            mrmax = sum;
    }

    // 中点的最大值
    max = std::max(max, mlmax + mrmax + A[mid]);

    return max;
}

