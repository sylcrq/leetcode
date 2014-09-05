#include <algorithm>

// 一维动态规划
// jump[i] = max( jump[i-1], A[i-1] ) - 1
bool canJump(int A[], int n)
{
    int prev = 0;

    for(int i=1; i<n; i++)
    {
        int jump = std::max(prev, A[i-1]) - 1;

        if(jump < 0) return false;

        prev = jump;
    }

    return true;
}
