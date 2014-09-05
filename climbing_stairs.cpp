#include <vector>

// 递归
int climbStairs_recursive(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;

    return climbStairs_recursive(n-1) + climbStairs_recursive(n-2);
}

// 优化时间复杂度
int climbStairs_optimize(int n)
{
    std::vector<int> v(n+1, 0);

    v[1] = 1;
    v[2] = 2;

    for(int i=3; i<=n; i++)
    {
        v[i] = v[i-1] + v[i-2];
    }

    return v[n];
}

// 继续优化空间复杂度
int climbStairs(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;

    int prev = 2;
    int pprev = 1;
    int result = 0;

    for(int i=3; i<=n; i++)
    {
        result = prev + pprev;
        pprev = prev;
        prev = result;
    }

    return result;
}

