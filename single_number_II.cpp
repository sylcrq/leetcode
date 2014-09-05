#include <iostream>

int singleNumber_ii(int A[], int n)
{
    int tmp[32] = {0};
    int number = 0;

    // 统计数组中所有的数在二进制位[31...0]上出现的次数
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<32; j++)
        {
            tmp[j] += (A[i] & (1<<j)) >> j;
        }
    }

    for(int i=0; i<32; i++)
    {
        if(tmp[i] % 3 != 0)
            number += (1 << i);
    }

    return number;
}

