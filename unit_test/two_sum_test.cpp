#include "gtest/gtest.h"

#include <vector>

std::vector<int> twoSum(std::vector<int> &numbers, int target);

TEST(TwoSumTestCase, Normal)
{
    int a[] = {2, 7, 11, 15};

    std::vector<int> numbers(a, a+4);
    std::vector<int> result = twoSum(numbers, 9);

    EXPECT_EQ(1, result[0]);
    EXPECT_EQ(2, result[1]);

    //-------------------------
    int b[] = {1, 4, 2, 23, 11, 8, 62, 34, 23, 9, 10};

    std::vector<int> numbers_2(b, b+11);
    std::vector<int> result_2 = twoSum(numbers_2, 17);

    EXPECT_EQ(6, result_2[0]);
    EXPECT_EQ(10, result_2[1]);

    //-------------------------
    int c[] = {0, 4, 3, 0};
    std::vector<int> numbers_3(c, c+4);
    std::vector<int> result_3 = twoSum(numbers_3, 0);

    EXPECT_EQ(1, result_3[0]);
    EXPECT_EQ(4, result_3[1]);
}
