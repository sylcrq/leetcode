#include "gtest/gtest.h"

int numTrees(int n);

TEST(UniqueBinarySearchTreesTestCase, Normal)
{
    EXPECT_EQ(1, numTrees(0));
    EXPECT_EQ(1, numTrees(1));
    EXPECT_EQ(2, numTrees(2));
    EXPECT_EQ(5, numTrees(3));
    EXPECT_EQ(42, numTrees(5));
}
