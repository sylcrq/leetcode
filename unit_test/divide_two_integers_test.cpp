#include "gtest/gtest.h"
#include <limits.h>

int divide(int dividend, int divisor); 

TEST(DivideTwoIntegersTestCase, Normal)
{
    EXPECT_EQ(2, divide(5, 2));
    EXPECT_EQ(3, divide(10, 3));
    EXPECT_EQ(67, divide(469, 7));

    EXPECT_EQ(0, divide(0, 128));
    EXPECT_EQ(INT_MAX, divide(1, 0));
    EXPECT_EQ(INT_MAX, divide(INT_MIN, -1));

    EXPECT_EQ(-1, divide(3475, -3475));
    EXPECT_EQ(INT_MIN/2, divide(INT_MIN, 2));
}
