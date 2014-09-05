#include "gtest/gtest.h"

int climbStairs(int n);

TEST(ClimbingStairsTestCase, Normal)
{
    EXPECT_EQ(1, climbStairs(1));
    EXPECT_EQ(2, climbStairs(2));
    EXPECT_EQ(5, climbStairs(4));
    EXPECT_EQ(89, climbStairs(10));

}
