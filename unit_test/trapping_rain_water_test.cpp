#include "gtest/gtest.h"

int trap(int A[], int n);

TEST(TrappingRainWaterTestCase, Normal)
{
    int a[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    EXPECT_EQ(6, trap(a, 12));
}
