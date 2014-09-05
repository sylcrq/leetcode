#include "gtest/gtest.h"

int uniquePaths(int m, int n);

TEST(UniquePathsTestCase, Normal)
{
    EXPECT_EQ(4, uniquePaths(2, 4));
    EXPECT_EQ(21, uniquePaths(3, 6));
}
