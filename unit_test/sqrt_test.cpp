#include "gtest/gtest.h"
#include <iostream>

int sqrt(int x);


TEST(SqrtTestCase, Normal)
{
    EXPECT_EQ(46340, sqrt(2147483647));
    EXPECT_EQ(46339, sqrt(2147395599));
}
