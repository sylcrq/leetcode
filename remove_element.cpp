#include <algorithm>

// 与数组尾部元素交换删除
int removeElement(int A[], int n, int elem)
{
    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        while(start <= end && A[end] == elem)
        {
            end--;
            n--;
        }

        while(start <= end && A[start] != elem)
        {
            start++;
        }

        if(start <= end)
        {
            std::swap(A[start], A[end]);

            start++;
            end--;
            n--;
        }
    }

    return n;
}

// 优化
int removeElement_ii(int A[], int n, int elem)
{
    int num = 0;

    for(int i=0; i<n; i++)
    {
        if(A[i] != elem)
        {
            A[num++] = A[i];
        }
    }

    return num;
}
