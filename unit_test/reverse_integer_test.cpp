#include "gtest/gtest.h"


int reverse(int x);
int reverse_ii(int x);

TEST(ReverseIntegerTestCase, Positive)
{
    EXPECT_EQ(321, reverse(123));
    EXPECT_EQ(321, reverse_ii(123));
}

TEST(ReverseIntegerTestCase, Negative)
{
    EXPECT_EQ(-123, reverse(-321));
    EXPECT_EQ(-123, reverse_ii(-321));
}

TEST(ReverseIntegerTestCase, MultipleOf10)
{
    EXPECT_EQ(1, reverse(100));
    EXPECT_EQ(1, reverse_ii(100));
}

TEST(ReverseIntegerTestCase, Overflow)
{
    EXPECT_EQ(-1, reverse_ii(1000000003));
}
