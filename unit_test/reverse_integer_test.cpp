#include "gtest/gtest.h"


int reverse(int x);

TEST(ReverseIntegerTestCase, Positive)
{
    EXPECT_EQ(321, reverse(123));
}

TEST(ReverseIntegerTestCase, Negative)
{
    EXPECT_EQ(-123, reverse(-321));
}

TEST(ReverseIntegerTestCase, MultipleOf10)
{
    EXPECT_EQ(1, reverse(100));
}

TEST(ReverseIntegerTestCase, Overflow)
{
}
