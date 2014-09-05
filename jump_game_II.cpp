
int jump(int A[], int n)
{
    // 维护一个通过steps步,可以到达的范围[start, end]
    int start = 0;
    int end = 0;
    int steps = 0;

    while(end < n - 1)
    {
        int max = end;
        steps++;

        for(int i=start; i<=end; i++)
        {
            if(A[i] + i >= n - 1)
                return steps;

            if(A[i] + i > max)
                max = A[i] + i;
        }

        start = end + 1;
        end = max;

        // 终点不可达
        if(start > end)
        {
            steps = -1;
            break;
        }
    }

    return steps;
}
