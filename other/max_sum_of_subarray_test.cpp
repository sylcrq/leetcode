#include <limits>

#include "gtest/gtest.h"

int max_sum_of_subarray(const int* array, int array_len);
int max_sum_of_subarray2(const int* array, int array_len);

TEST(MaxSumOfSubArrayTestCase, InvalidInput)
{
    int a[10] = {0};

    EXPECT_EQ(std::numeric_limits<int>::min(), max_sum_of_subarray(NULL, 10));
    EXPECT_EQ(std::numeric_limits<int>::min(), max_sum_of_subarray(a, -1));
    EXPECT_EQ(std::numeric_limits<int>::min(), max_sum_of_subarray(NULL, -1));

    EXPECT_EQ(std::numeric_limits<int>::min(), max_sum_of_subarray2(NULL, 10));
    EXPECT_EQ(std::numeric_limits<int>::min(), max_sum_of_subarray2(a, -1));
    EXPECT_EQ(std::numeric_limits<int>::min(), max_sum_of_subarray2(NULL, -1));
}

TEST(MaxSumOfSubArrayTestCase, AllPositive)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //10 == sizeof(a) / sizeof(int)
    EXPECT_EQ(55, max_sum_of_subarray(a, 10));
    EXPECT_EQ(55, max_sum_of_subarray2(a, 10));
}

TEST(MaxSumOfSubArrayTestCase, AllNegative)
{
    int a[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};

    EXPECT_EQ(-1, max_sum_of_subarray(a, 10));
    EXPECT_EQ(-1, max_sum_of_subarray2(a, 10));
}

TEST(MaxSumOfSubArrayTestCase, Normal)
{
    int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};

    EXPECT_EQ(18, max_sum_of_subarray(a, 8));
    EXPECT_EQ(18, max_sum_of_subarray2(a, 8));
}
