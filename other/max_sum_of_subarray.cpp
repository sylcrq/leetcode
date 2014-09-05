#include <limits>
#include <iostream>

//求子数组的最大和
//输入一个整形数组，数组里有正数也有负数
//数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和
//求所有子数组的和的最大值。要求时间复杂度为O(n)

//暴力枚举
//时间复杂度 O(n^2)
//附加空间复杂度 O(1)
int max_sum_of_subarray(const int* array, int array_len)
{
    if(!array || array_len <= 0)
    {
        std::cout << "max_sum_of_subarray: invalid parameters" << std::endl;
        return std::numeric_limits<int>::min();
    }
    //printf("len = %d\n", array_len);

    int tmp = 0;
    int max = std::numeric_limits<int>::min();

    for(int i=0; i<array_len; i++)
    {
        for(int j=i; j<array_len; j++)
        {
            if(i == j)
                tmp = array[i];
            else
                tmp += array[j];

            max = (tmp > max) ? tmp : max;
            //printf("%d\n", max);
        }
    }

    return max;
}


//时间复杂度 O(n)
//附加空间复杂度 O(1)
int max_sum_of_subarray2(const int* array, int array_len)
{
    if(!array || array_len <= 0)
    {
        return std::numeric_limits<int>::min();
    }

    int tmp = 0;
    int max = std::numeric_limits<int>::min();

    for(int i=0; i<array_len; i++)
    {
        tmp += array[i];

        max = (tmp > max) ? tmp : max;

        //
        if(tmp < 0) tmp = 0;
    }

    return max;
}

